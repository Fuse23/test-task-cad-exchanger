#include "../inc/Helix.h"

Helix::Helix(double radius, double step) {
    if (radius < 0) {
        throw RadiusNegative();
    }

    this->_radius = radius;
    this->_step = step;
}

double Helix::getRadius() const { return this->_radius; }
double Helix::getStep() const { return this->_step; }

std::vector<double> Helix::getPoint(double t) const {
    double x = this->getRadius() * cos(t);
    double y = this->getRadius() * sin(t);
    double z = this->getStep() * t / (2 * M_PI);

    return {x, y, z};
}

std::vector<double> Helix::getDerevative(double t) const {
    double dx = -this->getRadius() * sin(t);
    double dy = this->getRadius() * cos(t);
    double dz = this->getStep() / (2 * M_PI);

    return {dx, dy, dz};
}

std::string Helix::toString() const {
    return std::string(
        "Helix with radius: " + std::to_string(this->getRadius())
        + ", step: " + std::to_string(this->getStep())
    );
}

const char *Helix::RadiusNegative::what() const throw() {
    return "Radius is negative!";
}
