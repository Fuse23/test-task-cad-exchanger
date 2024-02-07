#ifndef __CIRCLE_CONTAINER_H__
# define __CIRCLE_CONTAINER_H__

# include <list>
# include <algorithm>
# include <memory>

# include "Circle.h"
# include "CurveContainer.h"

class CircleContainer : public std::list<Circle*> {
    public:
        CircleContainer() = delete;
        explicit CircleContainer(CurveContainer & curveContainer);

        double computeTotalSumOfRadius() const;

        void printContainer() const;
};

#endif  // __CIRCLE_CONTAINER_H__
