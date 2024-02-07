#ifndef __CURVE_CONTAINER_H__
# define __CURVE_CONTAINER_H__

# include <list>
# include <random>
# include <time.h>
# include <iostream>

# include "Circle.h"
# include "Ellipse.h"
# include "Helix.h"

class CurveContainer : public std::list<Curve*> {
    public:
        CurveContainer() = delete;
        explicit CurveContainer(int count);

        void printCoordinatesAndDerevatives(double t) const;
};

#endif  // __CURVE_CONTAINER_H__
