#pragma once

#include <cstdint>
#include <vector>

#include "raylib.h"

// A struct that contains data of all particles for the simulation.
struct Particles
{
    // Vector of particle positions
    std::vector<Vector2> positions;

    // Vector of particle directions
    std::vector<int> directions;

    // Vector of particle velocities
    std::vector<float> velocities;

    // Vector that stores the "alive" value of the particles
    std::vector<uint8_t> isAlive;

    /*
    *  Count that keeps track of how many particles are "alive"
    *  Used for checking if the simulation should end without
    *  checking the isAlive vector. 
    */
    int particleCount;
};