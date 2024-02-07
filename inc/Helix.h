#ifndef __HELIX_H__
# define __HELIX_H__

# include "Curve.h"

class Helix : public Curve {
    public:
        Helix() = delete;
        explicit Helix(double radius, double step);

        ~Helix() = default;

        double getRadius() const;
        double getStep() const;

        virtual std::vector<double> getDerevative(double t) const override;
        virtual std::vector<double> getPoint(double t) const override;

        virtual std::string toString() const override;

        class RadiusNegative : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        double _radius;
        double _step;
};

#endif  // __HELIX_H__
