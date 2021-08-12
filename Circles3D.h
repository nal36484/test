#pragma once
#include "Curves3D.h"

class Circles3D : public Curves3D
{
private: 
	double rad{};
public:
	Circles3D();
	Circles3D(const Point3D& center, double radius);
	virtual ~Circles3D();

	double getRadius();
	virtual Point3D curve_point(double t) const;
	virtual Vector3D curve_vector(double t) const;

};

