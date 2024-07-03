#ifndef CALCULATESUN_H
#define CALCULATESUN_H

class CalculateSun
{
public:
    static double DeclinationPos(double date);
    static double EquationPos(double date);
    static double MidDay(double date, double time);
    static double AngleTime(double date, double angle, double time, double lat, int invert = 0);
    static double NightPortion(double night);
    static double DayPortion(double time);
    static double RiseSetAngle(double elv = 0);
};

#endif
