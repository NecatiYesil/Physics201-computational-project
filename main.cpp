#include <iostream>
#include <math.h>
#include <fstream>
#include <cmath>
#include "euler.h"

std::ofstream cv_bow("comp_velocity_bow.txt");
std::ofstream av_bow("analy_velocity_bow.txt");
std::ofstream cp_bow("comp_position_bow.txt");
std::ofstream ap_bow("analy_position_bow.txt");
std::ofstream cv_bass("comp_velocity_bass.txt");
std::ofstream av_bass("analy_velocity_bass.txt");
std::ofstream cp_bass("comp_position_bass.txt");
std::ofstream ap_bass("analy_position_bass.txt");
std::ofstream cv_base("comp_velocity_base.txt");
std::ofstream av_base("analy_velocity_base.txt");
std::ofstream cp_base("comp_position_base.txt");
std::ofstream ap_base("analy_position_base.txt");

int main()
{
    Euler bowling;
    Euler basketball;
    Euler baseball;
    double bow_area = bowling.get_area_bow();
    double bow_mass = bowling.get_mass_bow();
    double bass_area = basketball.get_area_bass();
    double bass_mass = basketball.get_mass_bass();
    double base_area = baseball.get_area_base();
    double base_mass = baseball.get_mass_base();

    bowling.comp_velocity(bow_area, bow_mass,cv_bow);
    bowling.analy_velocity(bow_area, bow_mass, av_bow);
    bowling.comp_position(bow_area, bow_mass, cp_bow);
    bowling.analy_position(bow_area, bow_mass, ap_bow);
    basketball.comp_velocity(bass_area, bass_mass, cv_bass);
    basketball.analy_velocity(bass_area, bass_mass, av_bass);
    basketball.comp_position(bass_area, bass_mass, cp_bass);
    basketball.analy_position(bass_area, bass_mass, ap_bass);
    baseball.comp_velocity(base_area, base_mass, cv_base);
    baseball.analy_velocity(base_area, base_mass, av_base);
    baseball.comp_position(base_area, base_mass, cp_base);
    baseball.analy_position(base_area, base_mass, ap_base);
    
    return 0;
}
