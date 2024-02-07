#include "../inc/CircleContainer.h"

CircleContainer::CircleContainer(CurveContainer & curveContainer) {
    for (const auto &curve : curveContainer) {
        Circle *circle = dynamic_cast<Circle*>(curve);
        if (circle) {
            this->emplace_back(new Circle(*circle));
        }
    }
}

double CircleContainer::computeTotalSumOfRadius() const {
    double sum = 0.0;

    for (const auto &circle : *this) {
        sum += circle->getRadius();
    }

    return sum;
}

void CircleContainer::printContainer() const {
    for (const auto &circle : *this) {
        std::cout << circle << " " << circle->toString() << std::endl;
    }
}
