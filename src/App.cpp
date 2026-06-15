#include "App.hpp"

#include "raylib.h"

namespace App {

Particles App::initializeParticles(int amountOfParticles, float vx, float vy)
{
    Particles particles;

    if (amountOfParticles < 0) {
        amountOfParticles = 0;
    }

    particles.particleCount = amountOfParticles;
    particles.positions.assign(static_cast<std::size_t>(amountOfParticles), Vector2{0.0f, 0.0f});
    particles.velocities.assign(static_cast<std::size_t>(amountOfParticles), Vector2{vx, vy});
    particles.isAlive.assign(static_cast<std::size_t>(amountOfParticles), 1);

    return particles;
}

void App::drawParticle(Vector2 position)
{
    DrawCircleV(position, 2.0f, WHITE);
}

void App::drawParticles(const Particles& p)
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

void App::updateParticles(Particles& particle, const Planet& planet, float dt, float strength)
{
    for (size_t i = 0; i < particle.positions.size(); i++)
    {
        if (particle.isAlive[i] != 0)
        {
            // Update velocity
            float distance_x = planet.position.x - particle.positions[i].x; 
            float distance_y = planet.position.y - particle.positions[i].y;
            float distance = std::sqrt(distance_x*distance_x + distance_y*distance_y);
            float acceleration = planet.mass / (distance * distance);

            particle.velocities[i].x += (distance_x / distance) * acceleration * dt;
            particle.velocities[i].y += (distance_y / distance) * acceleration * dt;

            // Update position based on new velocity
            particle.positions[i].x += particle.velocities[i].x * dt;
            particle.positions[i].y += particle.velocities[i].y * dt;
        }
    }
}

bool App::areParticlesAlive(const Particles& p)
{
    return p.particleCount > 0;
}

Planet App::initializePlanet(float mass, Vector2 position, float radius)
{
    Planet planet;
    planet.mass = mass;
    planet.position = position;
    planet.gravitationalForce = 
}

} // namespace App