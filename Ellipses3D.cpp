#include "Ellipses3D.h"
#include <cmath>
Ellipses3D::Ellipses3D() = default;
Ellipses3D::Ellipses3D(const Point3D & center, double radius_x, double radius_y)
    : Curves3D(center), rad_x{ radius_x }, rad_y{ radius_y } {}
Ellipses3D::~Ellipses3D(){}

Curves3D::Point3D Ellipses3D::curve_point(double t) const
{
    return Point3D
    {
        rad_x * std::cos(t) + c.x,
        rad_y * std::sin(t) + c.y,
        c.z
    };
}

Curves3D::Vector3D Ellipses3D::curve_vector(double t) const
{
    return Vector3D
    {
        -1 * rad_x * std::sin(t),
        rad_y * std::cos(t)
    };
}
   