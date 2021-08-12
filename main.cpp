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
	constexpr size_t sz = 10;   // ������ ������� �������
	const double pi = std::acos(-1);    
	std::vector<PCurves> curves_vec;  // ������ ���������� �� ������� �������� ������
	{
		Curves_generator s_gen;  
		s_gen.set_diapason(-10, 10);    
		for (size_t i{}; i < sz; ++i)
			curves_vec.emplace_back(s_gen.random_curve());   
	}

	using PCircles = std::shared_ptr<Circles3D>;  // ��������� ���� - ����� ��������� �� Circles3D

	std::vector<PCircles> circles_vec;    // ������ ���������� �� Circles3D �� ������� ����������

	double radius_sum{};    // ����� �������� Circles3D
	for (auto& pc : curves_vec)
	{
		const std::type_info& ti{ typeid(*pc) };    // ���������� � ���� �������, �� ������� ��������� pc �� ������� ����������

		std::cout << ti.name() << ' '   // ������� ��� ����
			<< pc->curve_point(pi / 4) << ' '   // ����� ������, �������� ����������
			<< pc->curve_vector(pi / 4) << std::endl;   // ������(������ ����������� - �����������) � ���������� �����

		if (ti.hash_code() == typeid(Circles3D).hash_code()) // ���� ������� ������ - ��������� �� Circles3D
		{
			circles_vec.emplace_back(std::dynamic_pointer_cast<Circles3D>(pc));   // ������ ��� � ��������� �� Circles3D
			radius_sum += circles_vec.back()->getRadius();  // ������� ������
			std::cout << "to another vector -->\n"; // debug (����� ������� ��� ������)
		}
		std::cout << std::endl;
	}
	std::sort(circles_vec.begin(), circles_vec.end(), [](const PCircles& lh, const PCircles& rh)	// ��������� �� �������
		{
			return lh->getRadius() < rh->getRadius();
		});
	for (auto& pc : circles_vec)	// ������������� ���������������
		std::cout << pc->getRadius() << std::endl;
	std::cout << "sum = " << radius_sum << std::endl;	// � ����� �������� ���� Circles3D
}

