#include "./inc/3DGeometricCurve.h"

int main() {
    CurveContainer *curveContainer = new CurveContainer(30);
    CircleContainer *circleContainer = new CircleContainer(*curveContainer);

    std::cout << "Container with curves and t = pi / 4" << std::endl;
    curveContainer->printCoordinatesAndDerevatives(M_PI / 4);

    std::cout << std::endl << "Container with circles" << std::endl;
    circleContainer->printContainer();
    std::cout << std::endl << "Total sum of circles in the container: "
            << circleContainer->computeTotalSumOfRadius() << std::endl;
    circleContainer->sort([](Circle *a, Circle *b) {
             return a->getRadius() < b->getRadius();
    });
    std::cout << std::endl << "Sorted container with circles" << std::endl;
    circleContainer->printContainer();

    delete curveContainer;
    delete circleContainer;

    return 0;
}
