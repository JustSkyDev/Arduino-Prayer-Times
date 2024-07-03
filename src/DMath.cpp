#include "DMath.h"
#include <math.h>
#include <Arduino.h>

double DMath::dtr(double d)
{
    return (d * M_PI) / 180.0;
}

double DMath::rtd(double r)
{
    return (r * 180.0) / M_PI;
}

double DMath::sin(double d)
{
    return ::sin(dtr(d));
}

double DMath::cos(double d)
{
    return ::cos(dtr(d));
}

double DMath::tan(double d)
{
    return ::tan(dtr(d));
}

double DMath::arcsin(double d)
{
    return rtd(::asin(d));
}

double DMath::arccos(double d)
{
    return rtd(::acos(d));
}

double DMath::arctan(double d)
{
    return rtd(::atan(d));
}

double DMath::arccot(double x)
{
    return rtd(::atan(1 / x));
}

double DMath::arctan2(double y, double x)
{
    return rtd(::atan2(y, x));
}

double DMath::fix(double a, double b)
{
    double A = a - b * floor(a / b);
    return A < 0 ? A + b : A;
}

double DMath::fixAngle(double a)
{
    return fix(a, 360.0);
}

double DMath::fixHour(double a)
{
    return fix(a, 24.0);
}

double DMath::timeDiff(double timea, double timeb)
{
    return fixHour(timeb - timea);
}

double DMath::julianDate(int year, int month, int day)
{
    int y = year, m = month, d = day;

    if (month <= 2)
    {
        y -= 1;
        m += 12;
    }

    double A = floor(y / 100);
    double B = 2 - A + floor(A / 4);

    double Date = floor(365.25 * (y + 4716)) +
                  floor(30.6001 * (m + 1)) +
                  d + B - 1524.5;

    return Date;
}
