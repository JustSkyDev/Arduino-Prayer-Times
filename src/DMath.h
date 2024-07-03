#ifndef DMATH_H
#define DMATH_H

class DMath
{
public:
    static double dtr(double d);
    static double rtd(double r);
    static double sin(double d);
    static double cos(double d);
    static double tan(double d);
    static double arcsin(double d);
    static double arccos(double d);
    static double arctan(double d);
    static double arccot(double x);
    static double arctan2(double y, double x);
    static double fix(double a, double b);
    static double fixAngle(double a);
    static double fixHour(double a);
    static double timeDiff(double timea, double timeb);
    static double julianDate(int year, int month, int day);
};

#endif
