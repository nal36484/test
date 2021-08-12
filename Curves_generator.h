#pragma once
#include <iostream>
#include <random>
#include <typeinfo>
#include "Curves3D.h"
#include "Circles3D.h"
#include "Ellipses3D.h"
#include "Helixes3D.h"


constexpr double eps = 1e-6;
using PCurves = std::shared_ptr<Curves3D>; // псевдоним типа - умный указатель на базовый класс

class Curves_generator
{
	enum curves_t{ circles_t, ellipses_t, helixes_t };
	static std::random_device rd;
	std::uniform_real_distribution<double> udd{ -1, 1 };    // генератор случайных вещественных чисел(ГСВЧ)
	std::uniform_int_distribution<> usd{ circles_t, helixes_t };   // генератор случайных типов объектов
public:
	//Curves_generator();
	//~Curves_generator();
	void set_diapason(double min, double max);   
	
	PCurves circles();
	PCurves ellipses();
	PCurves helixes();
	PCurves random_curve();
};
