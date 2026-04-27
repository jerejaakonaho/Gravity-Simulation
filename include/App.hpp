#pragma once

#include <cstddef>
#include <cmath>

#include "raylib.h"


#include "Particles.hpp"
#include "Planet.hpp"

namespace App {
    // PARTICLES

    // Initializes particles struct
    Particles initializeParticles(int amountOfParticles, float velocity);

    void drawParticle(Vector2 position);

    /*
    *  Draws particles
    */
    void drawParticles(const Particles& p);

    /*
    *  Update the positions and direction of particles.
    */
    void updateParticles(Particles& p);

    /*
    *  Returns the status of particles,
    *  if any are alive keep drawing.
    */
    bool areParticlesAlive(const Particles& p);


    // PLANET

    // Initializes planet struct
    Planet initializePlanet(float mass, Vector2 position, float radius);

    // Draws planet
    void drawPlanet(const Planet& p);


    // MAIN LOOP

    /*
    *  Initialization
    *       Calculates track of dt for consistent speed for all machines
    *       Closes if !(isRunning)
    *       Check if more particles are spawned
    *  
    *  Update the particles
    *       - Calculate forces (gravity)
    *       - Update speed and direction based on forces
    *       - Position = Position + (Velocity * dt)
    *       - If particle is inside planet or outside screen isAlive -> 0
    * 
    *  Render particles
    *       - Erase old particles
    *       - Draw the particles at new locations
    *       - Update the window
    */
    void run();
}