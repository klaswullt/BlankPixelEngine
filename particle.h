#pragma once
#include "vec3d.h"
#include <chrono>
#include <random>
#define PI 3.14159265

enum status { dead,alive };


struct particle_message
{

    status flag;
};

class particle :
    public vec3d
{
public:


    std::default_random_engine generator;

    bool collide;

    vec3d position;

    vec3d Velocity;

    vec3d Force;

    vec3d Opposite_Force;

    double energy;

    double acceleration;


    particle_message update();

    particle(double x, double y, double z);

};

