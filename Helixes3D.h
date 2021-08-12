#pragma once
#include "Curves3D.h"

class Helixes3D : public Curves3D
{
private:
	double rad{};
	double step{};
public:
	Helixes3D();
	Helixes3D(const Point3D& center, double radius, double step);
    virtual ~Helixes3D();

	virtual Point3D curve_point(double t) const override;
	virtual Vector3D curve_vector(double t) const override;
};

