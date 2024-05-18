#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <random>

template<typename T>
struct Vec3 {
    T x, y, z;

    Vec3 operator+(const Vec3& b) const {
        return Vec3{x + b.x, y + b.y, z + b.z};
    }

    Vec3 operator-(const Vec3& b) const {
        return Vec3{x - b.x, y - b.y, z - b.z};
    }

    Vec3 operator*(T b) const {
        return Vec3{x * b, y * b, z * b};
    }

    Vec3& operator+=(const Vec3& b) {
        x += b.x; y += b.y; z += b.z;
        return *this;
    }

    Vec3& operator-=(const Vec3& b) {
        x -= b.x; y -= b.y; z -= b.z;
        return *this;
    }
};

template<typename T>
struct Particle {
    Vec3<T> pos, vel, acc;
    T mass;
};

template<typename T>
class NBodySimulator {
public:
    NBodySimulator(int nParticles, T simTime, T boxSize, T dt = 0.01)
        : nParticles(nParticles), simTime(simTime), boxSize(boxSize), dt(dt) {
        particles.resize(nParticles);
        initializeParticles();
    }

    void simulate() {
        T time = 0;
        while (time < simTime) {
            computeForces();
            updateParticles();
            time += dt;
        }
        outputResults();
    }

private:
    int nParticles;
    T simTime, dt, boxSize, G = 666.67430, epsilon = 0.001;
    std::vector<Particle<T>> particles;

    void initializeParticles() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<T> disPos(0.0, boxSize);

        T mass1 = 1000.0; 
        T mass2 = 1000.0; 

        for (int i = 0; i < nParticles; ++i) {
            particles[i].pos = {disPos(gen), disPos(gen), disPos(gen)};
            particles[i].vel = {0, 0, 0};
            // Assign mass1 or mass2 based on even/odd index or any other criterion
            particles[i].mass = (i % 2 == 0) ? mass1 : mass2;
        }
    }


    void computeForces(){
        for (auto& p : particles){
            p.acc = {0,0,0};
        }

        for (int i = 0; i < nParticles; i++) {
            for (int j = i + 1; j < nParticles; j++) { // Only compute once for each pair
                Vec3<T> r = {
                    particles[j].pos.x - particles[i].pos.x,
                    particles[j].pos.y - particles[i].pos.y,
                    particles[j].pos.z - particles[i].pos.z
                };
                T distSq = r.x * r.x + r.y * r.y + r.z * r.z + epsilon * epsilon;
                T invDist = 1.0 / sqrt(distSq);
                T invDistCubed = invDist * invDist * invDist;
                T forceMag = G * particles[i].mass * particles[j].mass * invDistCubed;
                        
                Vec3<T> force = {r.x * forceMag, r.y * forceMag, r.z * forceMag};

                particles[i].acc += force * (1.0 / particles[i].mass);
                particles[j].acc -= force * (1.0 / particles[j].mass); // Correct application of Newton's Third Law
            }
        }

    }

    void updateParticles(){
        for (auto& p : particles){
            p.vel += p.acc * dt;
            p.pos += p.vel * dt;

            p.pos.x = fmod(p.pos.x, boxSize);
            p.pos.y = fmod(p.pos.y, boxSize);
            p.pos.z = fmod(p.pos.z, boxSize);
        }
    }

    void outputResults() {
        std::ofstream file("twoparticles.csv");
        for (const auto& p : particles) {
            file << p.pos.x << "," << p.pos.y << "," << p.pos.z << "," << p.mass << "\n";
        }
    }
};

int main() {
    int nParticles;
    double simTime, boxSize;
    std::cout << "Enter number of particles: ";
    std::cin >> nParticles;
    std::cout << "Enter simulation time: ";
    std::cin >> simTime;
    std::cout << "Enter box size: ";
    std::cin >> boxSize;

    NBodySimulator<double> sim(nParticles, simTime, boxSize);
    sim.simulate();

    return 0;
}
