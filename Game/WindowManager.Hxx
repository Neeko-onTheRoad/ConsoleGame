#ifndef __WINDOW_MANAGER_HXX__
#define __WINDOW_MANAGER_HXX__

#include <Windows.h>

#include "Vector2.Hxx"

namespace Game {

	class WindowManager {

	private:
		
		HWND window;
		HANDLE inputHandle;
		HANDLE outputHandle;
		Vector2Unsigned currentBufferSize;

	public:

		WindowManager();
		~WindowManager();

	public:

		void SetTitle(std::string_view title);

		std::string GetTitle() const;
		Vector2Unsigned const& GetCurrentBufferSize() const;

	public:

		void UpdateConsoleInfo();

		void DisableScroll() const;
		void DisableScrollBar() const;
		void DisableQuickEditMode() const;
		void SetCursorBlinking(bool blinking) const;

	};

}

#endif