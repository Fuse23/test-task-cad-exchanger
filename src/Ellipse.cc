#include "../inc/Ellipse.h"

Ellipse::Ellipse(double radiusX, double radiusY) {
    if (radiusX < 0) {
        throw RadiusXNegative();
    }

    if (radiusY < 0) {
        throw RadiusYNegative();
    }

    this->_radiusX = radiusX;
    this->_radiusY = radiusY;
}

double Ellipse::getRadiusX() const { return this->_radiusX; }
double Ellipse::getRadiusY() const { return this->_radiusY; }

std::vector<double> Ellipse::getPoint(double t) const {
    double x = this->getRadiusX() * cos(t);
    double y = this->getRadiusY() * sin(t);
    double z = 0.0;

    return {x, y, z};
}

std::vector<double> Ellipse::getDerevative(double t) const {
    double dx = -this->getRadiusX() * sin(t);
    double dy = this->getRadiusY() * cos(t);
    double dz = 0.0;

    return {dx, dy, dz};
}

std::string Ellipse::toString() const {
    return std::string(
        "Ellipse with radius-x: " + std::to_string(this->getRadiusX())
        + ", radius-y: " + std::to_string(this->getRadiusY())
    );
}

const char *Ellipse::RadiusXNegative::what() const throw() {
    return "Radius x is negative!";
}

const char *Ellipse::RadiusYNegative::what() const throw() {
    return "Radius y is negative!";
}
