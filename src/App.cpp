#include "App.hpp"

#include "raylib.h"

namespace App {

Particles initializeParticles(int amountOfParticles, float velocity)
{
    Particles particles;

    if (amountOfParticles < 0) {
        amountOfParticles = 0;
    }

    particles.particleCount = amountOfParticles;
    particles.positions.assign(static_cast<std::size_t>(amountOfParticles), Vector2{0.0f, 0.0f});
    particles.directions.assign(static_cast<std::size_t>(amountOfParticles), 0);
    particles.velocities.assign(static_cast<std::size_t>(amountOfParticles), velocity);
    particles.isAlive.assign(static_cast<std::size_t>(amountOfParticles), 1);

    return particles;
}

void drawParticle(Vector2 position)
{
    DrawCircleV(position, 2.0f, WHITE);
}

void drawParticles(const Particles& p)
{
    if (p.particleCount <= 0) {
        return;
    }

    for (std::size_t i = 0; i < p.positions.size(); ++i) {
        if (i < p.isAlive.size() && p.isAlive[i] == 0) {
            continue;
        }

        drawParticle(p.positions[i]);
    }
}


} // namespace App