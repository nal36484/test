#include "Curves_generator.h"

//Curves_generator::Curves_generator() = default;
//Curves_generator::~Curves_generator(){}

void Curves_generator::set_diapason(double min, double max)  
{
	if ((std::abs(max) + std::abs(min)) < 2 * eps)  // ���� �������� ��������� ������������ ������ ������ � ����,
		return; // ������ �� ������
	udd = decltype(udd){ min, max }; // ������ ��������� ����
}
PCurves Curves_generator::circles()
{   // ����� ���������� � ��������� � ������������ ������ ������ ������ Circles3D
        // � ���������� ����� ��������� �� ������� �����
    double radius{};
    while (radius < eps)    // ���������, ��� �� ������ ��� �� ������� ���������
        radius = std::abs(udd(rd)); // � > 0

    return std::make_shared<Circles3D>(Curves3D::Point3D{ udd(rd), udd(rd) }, radius);
}
PCurves Curves_generator::ellipses()
{   // ����� ���������� � ��������� � ������������ ������ ������ ������ Ellipses3D
        // � ���������� ����� ��������� �� ������� �����
    double rad_x{};
    while (rad_x < eps)  // ���������, ��� �� ������ ������ ��� �� ������� ���������
        rad_x = std::abs(udd(rd));   // � > 0

    double rad_y{};
    while (rad_y < eps)  // ���������, ��� �� ������ ������ ��� �� ������� ���������
        rad_y = std::abs(udd(rd));   // � > 0

    return std::make_shared<Ellipses3D>(Curves3D::Point3D{ udd(rd), udd(rd) }, rad_x, rad_y);
}
PCurves Curves_generator::helixes()
{   // ����� ���������� � ��������� � ������������ ������ ������ ������ Helixes3D
        // � ���������� ����� ��������� �� ������� �����
    double rad{};
    while (rad < eps)    // ���������, ��� �� ������ ��� �� ������� ���������
        rad = std::abs(udd(rd)); // � > 0

    double step{};
    while (std::abs(step) < eps)    // ���������, ��� �� ��� ��� �� ������� ���������
        step = udd(rd);

    return std::make_shared<Helixes3D>(Curves3D::Point3D{ udd(rd), udd(rd), udd(rd) }, rad, step);
}
PCurves Curves_generator::random_curve()
{   // ����� ���������� ��������� ������ �� ���������� ������
    switch (usd(rd))
    {
    case circles_t:
        return circles();
    case ellipses_t:
        return ellipses();
    case helixes_t:
        return helixes();
    default:
        return circles(); // �� ������ ������
    }
}
std::random_device Curves_generator::rd;