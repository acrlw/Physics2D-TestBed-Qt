// Physics2D-TestBed-Qt.cpp: 定义应用程序的入口点。
//


#include <iostream>
#include "dependencies/Physics2D/include/physics2d.h"
int main()
{
	Physics2D::Vector2 a(1, 2);
	std::cout << a.x << ", " << a.y << std::endl;
	return 0;
}
