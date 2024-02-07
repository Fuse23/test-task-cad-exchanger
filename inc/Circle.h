#ifndef __CIRCLE_H__
# define __CIRCLE_H__

# include "Curve.h"

class Circle : public Curve {
    public:
        Circle() = delete;
        explicit Circle(double _radius);
        explicit Circle(Circle & target);

        ~Circle() = default;

        double getRadius() const;

        virtual std::vector<double> getDerevative(double t) const override;
        virtual std::vector<double> getPoint(double t) const override;

        virtual std::string toString() const override;

        class RadiusNegative : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        double _radius;
};

#endif  // __CIRCLE_H__
