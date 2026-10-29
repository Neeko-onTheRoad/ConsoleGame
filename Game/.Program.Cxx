#include <iostream>
#include "Vector2.Hxx"

using namespace Game;

int main(void) {

	Vector2 v1(1, 2);

	std::cout
		<< v1.Swizzle(Vector2Swizzle::XX) << std::endl
		<< v1.Swizzle(Vector2Swizzle::XY) << std::endl
		<< v1.Swizzle(Vector2Swizzle::YX) << std::endl
		<< v1.Swizzle(Vector2Swizzle::YY) << std::endl;

}