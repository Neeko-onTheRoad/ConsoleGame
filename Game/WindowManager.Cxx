#include "WindowManager.Hxx"
#include "StringConvert.Hxx"

namespace Game {

	WindowManager::WindowManager() {
		this->window = GetConsoleWindow();
		this->inputHandle = GetStdHandle(STD_INPUT_HANDLE);
		this->outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		UpdateConsoleInfo();
	}

	WindowManager::~WindowManager() {
		delete this->window;
		delete this->inputHandle;
		delete this->outputHandle;
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
			static_cast<unsigned>(bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1),
			static_cast<unsigned>(bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1)
		};

	}

	void WindowManager::DisableScroll() const {
	
		DWORD mode;
		if (!GetConsoleMode(this->outputHandle, &mode)) return;
		if (!SetConsoleMode(this->outputHandle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) return;

		constexpr char sequence[] = "\x1b[?1049h";

		DWORD written;
		WriteConsoleA(
			this->outputHandle,
			sequence,
			sizeof(sequence) - 1,
			&written,
			nullptr
		);

	}

	void WindowManager::DisableScrollBar() const {
		ShowScrollBar(window, SB_BOTH, false);
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
