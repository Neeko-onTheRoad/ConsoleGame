#include <iostream>
#include "WindowManager.Hxx"
using namespace Game;

int main(void) {

	WindowManager manager;
	manager.DisableQuickEditMode();

	Vector2Unsigned previousBufferSize = Vector2Unsigned::Zero;
	manager.DisableScroll();

	while (true) {

		manager.UpdateConsoleInfo();
		manager.DisableScrollBar();
		manager.SetCursorBlinking(false);

		std::cout << manager.GetCurrentBufferSize() << std::endl;

	}

}