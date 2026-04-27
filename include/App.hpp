#pragma once

#include <cstddef>

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
    Planet initializePlanet(float mass, Vector2 position, float gravForce, float radius);

    // Draws planet
    void drawPlanet(const Planet& p);


    // MAIN LOOP

    void run(int amountOfParticles);
}