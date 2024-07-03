#include "PrayTimes.h"
#include "Sun.h"
#include "DMath.h"
#include <math.h>
#include <Arduino.h>

HrsMin convertToHrsMin(double rawTime)
{
    double timeFix = DMath::fixHour(rawTime + 0.5 / 60.0);
    int hours = floor(timeFix);
    int minutes = floor((timeFix - hours) * 60.0);

    HrsMin result;
    result.raw = rawTime;
    result.hours = hours;
    result.minutes = minutes;

    return result;
}

double getJulianDate(double lng, int yrs, int mth, int dy)
{
    return DMath::julianDate(yrs, mth, dy) - lng / (15.0 * 24.0);
}

double PrayTimes::asrTime(double date, double time)
{
    double decl = CalculateSun::DeclinationPos(date + time);
    double angle = -DMath::arccot(1.0 + DMath::tan(abs(lat - decl)));
    return CalculateSun::AngleTime(date, angle, time, lat, 1);
}

int PrayTimes::getTimezone(double longitude)
{
    return floor(longitude / 15);
}

void PrayTimes::SetCoordinate(double latitude, double longitude, bool auto_timezone)
{
    if (this->tz == 0 && auto_timezone)
    {
        this->tz = getTimezone(longitude);
    }
    this->lat = latitude;
    this->lng = longitude;
}

void PrayTimes::SetTimezone(int timezone)
{
    this->tz = timezone;
}

void PrayTimes::AdjustTime(int year, int month, int day)
{
    this->yrs = year;
    this->mth = month;
    this->dy = day;
}

void PrayTimes::AdjustDegree(double fajr_degree, double isha_degree)
{
    this->fajr_degree = fajr_degree;
    this->isha_degree = isha_degree;
}

HrsMin PrayTimes::getImsak()
{
    return convertToHrsMin(getFajr().raw - 10.0 / 60.0);
}

HrsMin PrayTimes::getFajr()
{
    double jdate = getJulianDate(lng, yrs, mth, dy);
    double angleTime = CalculateSun::AngleTime(jdate, this->fajr_degree, CalculateSun::DayPortion(this->fajr_degree), lat);
    angleTime += tz - lng / 15.0;
    return convertToHrsMin(angleTime);
}

HrsMin PrayTimes::getSunrise()
{
    double jdate = getJulianDate(lng, yrs, mth, dy);
    double angleTime = CalculateSun::AngleTime(jdate, CalculateSun::RiseSetAngle(), CalculateSun::DayPortion(6), lat);
    angleTime += tz - lng / 15.0;
    return convertToHrsMin(angleTime);
}

HrsMin PrayTimes::getDhuhr()
{
    double jdate = getJulianDate(lng, yrs, mth, dy);
    double angleTime = CalculateSun::MidDay(jdate, CalculateSun::DayPortion(12));
    angleTime += tz - lng / 15.0;
    return convertToHrsMin(angleTime);
}

HrsMin PrayTimes::getAsr()
{
    double jdate = getJulianDate(lng, yrs, mth, dy);
    double angleTime = asrTime(jdate, CalculateSun::DayPortion(13));
    angleTime += tz - lng / 15.0;
    return convertToHrsMin(angleTime);
}

HrsMin PrayTimes::getSunset()
{
    double jdate = getJulianDate(lng, yrs, mth, dy);
    double angleTime = CalculateSun::AngleTime(jdate, CalculateSun::RiseSetAngle(), CalculateSun::DayPortion(18), lat, 1);
    angleTime += tz - lng / 15.0;
    return convertToHrsMin(angleTime);
}

HrsMin PrayTimes::getMaghrib()
{
    return convertToHrsMin(getSunset().raw + 0.0 / 60.0);
}

HrsMin PrayTimes::getIsha()
{
    double jdate = getJulianDate(lng, yrs, mth, dy);
    double angleTime = CalculateSun::AngleTime(jdate, this->isha_degree, CalculateSun::DayPortion(this->isha_degree), lat, 1);
    angleTime += tz - lng / 15.0;
    return convertToHrsMin(angleTime);
}

HrsMin PrayTimes::getMidnight()
{
    double midnight = getSunset().raw + DMath::timeDiff(getSunset().raw, getSunrise().raw) / 2.0;
    return convertToHrsMin(midnight);
}
