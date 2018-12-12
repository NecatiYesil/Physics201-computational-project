#include "euler.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>

Euler::Euler(){
}

void Euler::comp_velocity(double a, double m, std::ostream& out){
    for(int i = 0; i < 5000; i++)
    {
        tn[i] = 0 + H*i;
        vn[0] = 0;
        an[i] = ((DRAG_COEFF*DENSITY_AIR*a*(vn[i]*vn[i]))/(2*m)) - g;
        vn[i+1] = vn[i] + an[i]*H;
        out << "TIME----||----VELOCITY" << std::endl;
        out << tn[i] << " --> " << fabs(vn[i]) << std::endl;
    }
}
        
void Euler::analy_velocity(double a, double m, std::ostream& out){
    for(int i = 0; i < 5000; i++)
    {
        vn[0] = 0;
        tn[0] = 0;
        vn[i] = sqrt((2*m*g)/(DRAG_COEFF*DENSITY_AIR*a)) * tanh(sqrt((DRAG_COEFF*DENSITY_AIR*a*g)/(2*m))*tn[i]);
        out << "TIME(s)----||----VELOCITY(m/s)" << std::endl;
        out << tn[i] << " --> " << vn[i] << std::endl;
    }
}

void Euler::comp_position(double a, double m, std::ostream& out){
    for(int i = 0; i < 5000; i++)
    {
        pn[0] = 440;
        pn[i+1] = pn[i] - vn[i]*H + DRAG_COEFF*an[i]*(pow(H,2));
        out << "TIME(s)----||----POSITION(m)" << std::endl;
        out << tn[i] << " --> " << pn[i] << std::endl;
        
        if(pn[i] < 0) break;
    }
}

void Euler::analy_position(double a, double m, std::ostream& out){
    for(int i = 0; i < 5000; i++)
    {
        pn[i] = (2*m)/(DRAG_COEFF*DENSITY_AIR*a) *log(cosh(sqrt((DRAG_COEFF*DENSITY_AIR*a*g)/(2*m))*tn[i]));
        out << "TIME(s)----||----POSITION(m)" << std::endl;
        out << tn[i] << " --> " << pn[i] << std::endl;

        if(pn[i] > 440) break;
    }
}

double Euler::get_area_bow(){
    return BOW_A; }
double Euler::get_mass_bow(){ 
    return BOW_M; }
double Euler::get_area_bass(){ 
    return BASS_A; }
double Euler::get_mass_bass(){ 
    return BASS_M; }
double Euler::get_area_base(){ 
    return BASE_A; }
double Euler::get_mass_base(){ 
    return BASE_M; }
