#ifndef __WINDOW_MANAGER_HXX__
#define __WINDOW_MANAGER_HXX__

#include <Windows.h>

#include "Vector2.Hxx"
#include "StringConvert.Hxx"
#include "ANSIEscapeCode.Hxx"
#include "WindowPrintBuffer.Hxx"

namespace Game {

	class WindowManager {

	private:
		
		HWND window;
		HANDLE inputHandle;
		HANDLE outputHandle;
		Vector2Size currentBufferSize;

	public:

		WindowManager();
		~WindowManager();

	public:

		void SetTitle(std::string_view title);

		std::string GetTitle() const;
		Vector2Size const& GetCurrentBufferSize() const;

	public:

		void UpdateConsoleInfo();

		void DisableScroll() const;
		void DisableScrollBar() const;
		void DisableQuickEditMode() const;
		void EnableVirtualTerminal() const;
		void SetCursorBlinking(bool blinking) const;

		void Print(WindowPrintBuffer const& buffer) const;

	};

}

#endif