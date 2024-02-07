#include "../inc/CurveContainer.h"

CurveContainer::CurveContainer(int count) {
    srand(time(nullptr));

    for (int i = 0; i < count; ++i) {
        int curveType = rand() % 3;  // 0: Circle, 1: Ellipse, 2: Helix

        double radius, radiusX, radiusY, step;

        try {
            Curve *curve;

            switch (curveType) {
                case 0:
                    radius = static_cast<double>(rand() % 10 + 1);
                    curve = new Circle(radius);
                    break;
                case 1:
                    radiusX = static_cast<double>(rand() % 10 + 1);
                    radiusY = static_cast<double>(rand() % 10 + 1);
                    curve = new Ellipse(radiusX, radiusY);
                    break;
                case 2:
                    radius = static_cast<double>(rand() % 10 + 1);
                    step = static_cast<double>(rand() % 5 + 1);
                    curve = new Helix(radius, step);
                    break;
                default:
                    break;
            }

            this->emplace_back(curve);

        } catch (std::exception & e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void print(std::vector<double> &_vector) {
    for (size_t i; i < _vector.size(); ++i) {
        if (i != _vector.size() - 1) {
            std::cout << _vector[i] << ", ";
        } else {
            std::cout << _vector[i] << ")";
        }
    }
}

void CurveContainer::printCoordinatesAndDerevatives(double t) const {
    for (const auto &curve : *this) {
        std::cout << curve << " ";

        std::vector<double> point = curve->getPoint(t);
        std::vector<double> derevative = curve->getDerevative(t);

        std::cout << curve->toString() << " point: (";
        print(point);

        std::cout << ", derevative: (";
        print(derevative);
        std::cout << std::endl;
    }
}
