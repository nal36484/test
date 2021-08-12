#include "Curves_generator.h"

//Curves_generator::Curves_generator() = default;
//Curves_generator::~Curves_generator(){}

void Curves_generator::set_diapason(double min, double max)  
{
	if ((std::abs(max) + std::abs(min)) < 2 * eps)  // если значения диапазона одновременно слишко близки к нулю,
		return; // ничего не меняем
	udd = decltype(udd){ min, max }; // меняем параметры ГСВЧ
}
PCurves Curves_generator::circles()
{   // метод генерирует и размещает в динамической памяти объект класса Circles3D
        // и возвращает умный указатель на базовый класс
    double radius{};
    while (radius < eps)    // проверяем, что бы радиус был не слишком маленьким
        radius = std::abs(udd(rd)); // и > 0

    return std::make_shared<Circles3D>(Curves3D::Point3D{ udd(rd), udd(rd) }, radius);
}
PCurves Curves_generator::ellipses()
{   // метод генерирует и размещает в динамической памяти объект класса Ellipses3D
        // и возвращает умный указатель на базовый класс
    double rad_x{};
    while (rad_x < eps)  // проверяем, что бы первый радиус был не слишком маленьким
        rad_x = std::abs(udd(rd));   // и > 0

    double rad_y{};
    while (rad_y < eps)  // проверяем, что бы второй радиус был не слишком маленьким
        rad_y = std::abs(udd(rd));   // и > 0

    return std::make_shared<Ellipses3D>(Curves3D::Point3D{ udd(rd), udd(rd) }, rad_x, rad_y);
}
PCurves Curves_generator::helixes()
{   // метод генерирует и размещает в динамической памяти объект класса Helixes3D
        // и возвращает умный указатель на базовый класс
    double rad{};
    while (rad < eps)    // проверяем, что бы радиус был не слишком маленьким
        rad = std::abs(udd(rd)); // и > 0

    double step{};
    while (std::abs(step) < eps)    // проверяем, что бы шаг был не слишком маленьким
        step = udd(rd);

    return std::make_shared<Helixes3D>(Curves3D::Point3D{ udd(rd), udd(rd), udd(rd) }, rad, step);
}
PCurves Curves_generator::random_curve()
{   // метод генерирует случайную фигуру из доступного набора
    switch (usd(rd))
    {
    case circles_t:
        return circles();
    case ellipses_t:
        return ellipses();
    case helixes_t:
        return helixes();
    default:
        return circles(); // на всякий случай
    }
}
std::random_device Curves_generator::rd;