#ifndef __CURVE_H__
# define __CURVE_H__

# include <vector>
# include <cmath>
# include <string>

class Curve {
    public:
        Curve() = default;

        virtual ~Curve() = default;

        virtual std::vector<double> getDerevative(double t) const = 0;
        virtual std::vector<double> getPoint(double t) const = 0;

        virtual std::string toString() const = 0;
};

#endif  // __CURVE_H__
