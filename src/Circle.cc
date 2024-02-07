#include "../inc/Circle.h"

Circle::Circle(double radius) {
    if (radius < 0) {
        throw RadiusNegative();
    }

    this->_radius = radius;
}

Circle::Circle(Circle & target) : _radius(target.getRadius()) {}


double Circle::getRadius() const { return this->_radius; }

std::vector<double> Circle::getDerevative(double t) const {
    double x = this->getRadius() * cos(t);
    double y = this->getRadius() * sin(t);
    double z = 0.0;

    return {x, y, z};
}

std::vector<double> Circle::getPoint(double t) const {
    double dx = -this->getRadius() * sin(t);
    double dy = this->getRadius() * cos(t);
    double dz = 0.0;

    return {dx, dy, dz};
}

std::string Circle::toString() const {
    return std::string("Circle with radius: " + std::to_string(this->getRadius()));
}

const char *Circle::RadiusNegative::what() const throw() {
    return "Radius is negative!";
}
