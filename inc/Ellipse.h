#ifndef __ELLIPSE_H__
# define __ELLIPSE_H__

# include "Curve.h"

class Ellipse : public Curve {
    public:
        Ellipse() = delete;
        explicit Ellipse(double radiusX, double radiusY);

        ~Ellipse() = default;

        double getRadiusX() const;
        double getRadiusY() const;

        virtual std::vector<double> getDerevative(double t) const override;
        virtual std::vector<double> getPoint(double t) const override;

        virtual std::string toString() const override;

        class RadiusXNegative : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class RadiusYNegative : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        double _radiusX;
        double _radiusY;
};

#endif  // __ELLIPSE_H__
