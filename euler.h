#ifndef EULER_H
#define EULER_H
#include <iostream>
#include <fstream>
#include <vector>

class Euler
{
    //density of air near sea level.
    const double DENSITY_AIR = 1.225; // kg/m^3
    //drag coeffiecient of the between ball and air.
    const double DRAG_COEFF = 0.5; 
    //acceleration due gravity.
    const double g = 9.81; // m/s^2
    //cross section area of the bowling ball
    const double BOW_A = 0.0366096154; // m^2
    //mass of the bowling ball.
    const double BOW_M = 7.257; //kg
    //cross section area of the basketball
    const double BASS_A = 0.04622; // m^2
    //mass of the basketball
    const double BASS_M = 0.625; // kg
    //cross section area of the baseball
    const double BASE_A = 0.176714587; //m^2
    //mass of the baseball
    const double BASE_M = 0.149; //kg
    //step size of euler's method
    const double H = 0.01;
    double vn[5000];
    double tn[5000];
    double an[5000];
    double pn[5000];
public:
    Euler();
    void comp_velocity(double a, double m, std::ostream& out);
    void analy_velocity(double a, double m, std::ostream& out);
    void comp_position(double a, double m, std::ostream& out);
    void analy_position(double a, double m, std::ostream& out);
    double get_area_bow();
    double get_mass_bow();
    double get_area_bass();
    double get_mass_bass();
    double get_area_base();
    double get_mass_base();
};

#endif
