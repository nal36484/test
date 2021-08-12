#pragma once
#include <iostream>

class Curves3D
{
public:
	struct Point3D { double x{}, y{}, z{}; };	// точка в 3-х мерном пространстве 

	friend std::ostream& operator<<(std::ostream& os, const Point3D& p)
	{	
		return os << "P{ " << p.x << ", " << p.y << ", " << p.z << " }";
	}
	//===============================================================>
	struct Vector3D { double x{}, y{}, z{}; };	// вектор в 3-х мерном пространстве

	friend std::ostream& operator<<(std::ostream& os, const Vector3D& v)
	{	
		return os << "V{ " << v.x << ", " << v.y << ", " << v.z << " }";
	}
protected:
	Point3D c;
	Curves3D();
	Curves3D(const Point3D& center);
public:
	virtual ~Curves3D();

	virtual Point3D curve_point(double t) const = 0;
	virtual Vector3D curve_vector(double t) const = 0;

}; 
