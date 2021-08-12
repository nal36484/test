#pragma once
#include "Curves3D.h"

class Ellipses3D : public Curves3D
{
private:
    double rad_x{};
    double rad_y{};
public:
    Ellipses3D();
    Ellipses3D(const Point3D& center, double radius_x, double radius_y);
    virtual ~Ellipses3D();

    virtual Point3D curve_point(double t) const override;
    virtual Vector3D curve_vector(double t) const override;
};

