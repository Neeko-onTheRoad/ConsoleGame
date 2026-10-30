#include "WindowManager.Hxx"
#include "StringConvert.Hxx"

namespace Game {

	WindowManager::WindowManager() {
		this->inputHandle = GetStdHandle(STD_INPUT_HANDLE);
		this->outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		UpdateConsoleInfo();
	}

	void WindowManager::SetTitle(std::string_view title) {
		SetConsoleTitleA(title.data());
	}

	Vector2Unsigned const& WindowManager::GetCurrentBufferSize() const {
		return this->currentBufferSize;
	}

	std::string WindowManager::GetTitle() const {
		wchar_t buffer[MAX_PATH];
		DWORD length = GetConsoleTitle(buffer, MAX_PATH);
		return WCharPToString(buffer);
	}

	void WindowManager::UpdateConsoleInfo() {
	
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

		GetConsoleScreenBufferInfo(
			this->outputHandle,
			&bufferInfo
		);

		this->currentBufferSize = {
			static_cast<unsigned>(bufferInfo.srWindow.Right - bufferInfo.srWindow.Left),
			static_cast<unsigned>(bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top)
		};

	}

	void WindowManager::DisableScrollBar() const {
	
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(this->outputHandle, &info);
		COORD new_size = {
			info.srWindow.Right - info.srWindow.Left + 1,
			info.srWindow.Bottom - info.srWindow.Top + 1
		};
		SetConsoleScreenBufferSize(this->outputHandle, new_size);

	}

	void WindowManager::DisableQuickEditMode() const {
	
		DWORD mode;
		if (!GetConsoleMode(this->inputHandle, &mode)) return;

		mode &= ~ENABLE_QUICK_EDIT_MODE;
		mode |= ENABLE_EXTENDED_FLAGS;

		SetConsoleMode(this->inputHandle, mode);
	
	}

	void WindowManager::SetCursorBlinking(bool blinking) const {

		CONSOLE_CURSOR_INFO cursorInfo;

		GetConsoleCursorInfo(this->outputHandle, &cursorInfo);
		cursorInfo.bVisible = blinking;
		SetConsoleCursorInfo(this->outputHandle, &cursorInfo);

	}

}
