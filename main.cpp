#pragma once
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include "Curves3D.h"
#include "Circles3D.h"
#include "Ellipses3D.h"
#include "Helixes3D.h"
#include "Curves_generator.h"

int main()
{
	constexpr size_t sz = 10;   // размер первого массива
	const double pi = std::acos(-1);    
	std::vector<PCurves> curves_vec;  // массив указателей на объекты базового класса
	{
		Curves_generator s_gen;  
		s_gen.set_diapason(-10, 10);    
		for (size_t i{}; i < sz; ++i)
			curves_vec.emplace_back(s_gen.random_curve());   
	}

	using PCircles = std::shared_ptr<Circles3D>;  // псевдоним типа - умный указатель на Circles3D

	std::vector<PCircles> circles_vec;    // массив указателей на Circles3D из первого контейнера

	double radius_sum{};    // сумма радиусов Circles3D
	for (auto& pc : curves_vec)
	{
		const std::type_info& ti{ typeid(*pc) };    // информация о типе объекта, на который указывает pc из первого контейнера

		std::cout << ti.name() << ' '   // выводим имя типа
			<< pc->curve_point(pi / 4) << ' '   // точку кривой, заданную параметром
			<< pc->curve_vector(pi / 4) << std::endl;   // вектор(первая производная - касательная) в предыдущей точке

		if (ti.hash_code() == typeid(Circles3D).hash_code()) // если текущий объект - указатель на Circles3D
		{
			circles_vec.emplace_back(std::dynamic_pointer_cast<Circles3D>(pc));   // кастим его к указателю на Circles3D
			radius_sum += circles_vec.back()->getRadius();  // плюсуем радиус
			std::cout << "to another vector -->\n"; // debug (можно удалить эту строку)
		}
		std::cout << std::endl;
	}
	std::sort(circles_vec.begin(), circles_vec.end(), [](const PCircles& lh, const PCircles& rh)	// сортируем по радиусу
		{
			return lh->getRadius() < rh->getRadius();
		});
	for (auto& pc : circles_vec)	// демонстрируем отсортированное
		std::cout << pc->getRadius() << std::endl;
	std::cout << "sum = " << radius_sum << std::endl;	// и сумму радиусов всех Circles3D
}

