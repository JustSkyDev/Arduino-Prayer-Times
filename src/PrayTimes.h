#ifndef PrayTimes_h
#define PrayTimes_h

struct HrsMin
{
    double raw;
    int hours;
    int minutes;
};

class PrayTimes
{
private:
    int yrs, mth, dy, tz = 0;
    double lng, lat;
    double fajr_degree = 18, isha_degree = 18;

    double asrTime(double date, double time);
    int getTimezone(double longitude);

public:
    void SetCoordinate(double latitude, double longitude, bool auto_timezone = true);
    void AdjustTime(int year, int month, int day);
    void SetTimezone(int timezone);
    void AdjustDegree(double fajr_degree, double isha_degree);
    HrsMin getImsak();
    HrsMin getFajr();
    HrsMin getSunrise();
    HrsMin getDhuhr();
    HrsMin getAsr();
    HrsMin getSunset();
    HrsMin getMaghrib();
    HrsMin getIsha();
    HrsMin getMidnight();
};

#endif