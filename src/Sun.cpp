#include "Sun.h"
#include "DMath.h"
#include <Arduino.h>

double CalculateSun::DeclinationPos(double date)
{
    double D = date - 2451545.0;
    double g = DMath::fixAngle(357.529 + 0.98560028 * D);
    double q = DMath::fixAngle(280.459 + 0.98564736 * D);
    double L = DMath::fixAngle(q + 1.915 * DMath::sin(g) + 0.02 * DMath::sin(2 * g));

    double R = 1.00014 - 0.01671 * DMath::cos(g) - 0.00014 * DMath::cos(2 * g);
    double e = 23.439 - 0.00000036 * D;

    double RA = DMath::arctan2(DMath::cos(e) * DMath::sin(L), DMath::cos(L)) / 15;
    double declination = DMath::arcsin(DMath::sin(e) * DMath::sin(L));

    return declination;
}

double CalculateSun::EquationPos(double date)
{
    double D = date - 2451545.0;
    double g = DMath::fixAngle(357.529 + 0.98560028 * D);
    double q = DMath::fixAngle(280.459 + 0.98564736 * D);
    double L = DMath::fixAngle(q + 1.915 * DMath::sin(g) + 0.02 * DMath::sin(2 * g));

    double R = 1.00014 - 0.01671 * DMath::cos(g) - 0.00014 * DMath::cos(2 * g);
    double e = 23.439 - 0.00000036 * D;

    double RA = DMath::arctan2(DMath::cos(e) * DMath::sin(L), DMath::cos(L)) / 15;
    double equation = q / 15.0 - DMath::fixHour(RA);

    return equation;
}

double CalculateSun::MidDay(double date, double time)
{
    double eqt = EquationPos(date + time);
    double noon = DMath::fixHour(12.0 - eqt);

    return noon;
}

double CalculateSun::AngleTime(double date, double angle, double time, double lat, int invert)
{
    double decl = DeclinationPos(date + time);
    double noon = MidDay(date, time);

    double t = (1.0 / 15.0) * DMath::arccos((-DMath::sin(angle) - DMath::sin(decl) * DMath::sin(lat)) / (DMath::cos(decl) * DMath::cos(lat)));

    return noon + (invert == 0 ? -t : t);
}

double CalculateSun::NightPortion(double night)
{
    double portion = 1.0 / 2.0;
    return portion * night;
}

double CalculateSun::DayPortion(double time)
{
    return time / 24.0;
}

double CalculateSun::RiseSetAngle(double elv)
{
    double angle = 0.0374 * sqrt(elv);
    return 0.833 + angle;
}
