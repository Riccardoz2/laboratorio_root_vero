#include "Particle.hpp"
#include <cmath>
// #include "TRandom.h"

void MainModule()
{
    Particle::AddParticleType((char *)"Pi+", 0.13957, 1);
    Particle::AddParticleType((char *)"Pi-", 0.13957, -1);
    Particle::AddParticleType((char *)"K+", 0.49367, 1);
    Particle::AddParticleType((char *)"K-", 0.49367, -1);
    Particle::AddParticleType((char *)"P+", 0.93827, 1);
    Particle::AddParticleType((char *)"P-", 0.93827, -1);
    Particle::AddParticleType((char *)"K*", 0.89166, 0, 0.05);

    gRandom->SetSeed();

    Int_t N{120};
    Particle EventParticles[N];
    double phi{};
    double theta{};
    double mean{1};
    double pulse{};
    double px{};
    double py{};
    double pz{};
    double x{};

    for (Int_t i = 0; i < 1E5; ++i)
    {
        for (Int_t j = 0; j < 1E2; ++j)
        {
            phi = gRandom->Uniform(0, (2 * 3.14));
            theta = gRandom->Uniform(0, 3.14);
            pulse = gRandom->Exp(mean);
            px = pulse * sin(theta) * cos(phi);
            py = pulse * sin(theta) * sin(phi);
            pz = pulse * cos(theta);

            EventParticles[j].SetP(px, py, pz);

            x = gRandom->Rndm();
            if (x < 0.01)
            {
                EventParticles[j].SetfIndex(6);
              //  EventParticles[j].Decay2body(Pi, K);
            }
            else if (x < 0.055)
            {
                EventParticles[j].SetfIndex(5);
            }
            else if (x < 0.1)
            {
                EventParticles[j].SetfIndex(4);
            }
            else if (x < 0.15)
            {
                EventParticles[j].SetfIndex(3);
            }
            else if (x < 0.2)
            {
                EventParticles[j].SetfIndex(2);
            }
            else if (x < 0.6)
            {
                EventParticles[j].SetfIndex(1);
            }
            else
            {
                EventParticles[j].SetfIndex(0);
            }
        }
    }
}