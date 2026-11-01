#include <iostream>
#include "Color.Hxx"
using namespace Game;

int main(void) {

	Color c = { 1.f, 1.f, 1.f };
	const auto bc = c.ToByteColor();

	std::cout << c;

}