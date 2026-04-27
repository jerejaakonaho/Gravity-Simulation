#pragma once


#include "raylib.h"


struct Planet
{
    // mass of the planet, used for calculating gravitationalForce
    float mass;

    // pair of doubles that show position
    Vector2 position;

    // Force applied to particles
    float gravitationalForce;

    // Radius of planet for rendering
    float radius;
};
