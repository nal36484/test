#include "Circles3D.h"
#include <cmath>

Circles3D::Circles3D() = default;
Circles3D::Circles3D(const Point3D & center, double radius)
    : Curves3D(center), rad{ radius } {}
Circles3D::~Circles3D() {}

double Circles3D::getRadius() { return rad; }

Curves3D::Point3D Circles3D::curve_point(double t) const
{
    return Point3D
    {
        rad * std::cos(t) + c.x,
        rad * std::sin(t) + c.y,
        c.z
    };
}

Curves3D::Vector3D Circles3D::curve_vector(double t) const
    {
        return Vector3D
        {
            -1 * rad * std::sin(t),
            rad * std::cos(t)
        };
    }