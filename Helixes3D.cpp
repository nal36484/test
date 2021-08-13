#include "Helixes3D.h"
#include <cmath>
Helixes3D::Helixes3D() = default;
Helixes3D::Helixes3D(const Point3D & center, double radius, double step)
    : Curves3D(center), rad{ radius }, step{ step } {}
Helixes3D::~Helixes3D() {}

Curves3D::Point3D Helixes3D::curve_point(double t) const
{
    return Point3D
    {
        rad * std::cos(t) + c.x,
        rad * std::sin(t) + c.y,
        step * t + c.z
    };
}

Curves3D::Vector3D Helixes3D::curve_vector(double t) const
{
    return Vector3D
    {
        rad * (std::cos(t) - t * std::sin(t)),
        rad * (std::sin(t) + t * std::cos(t)),
        step
    };
}
