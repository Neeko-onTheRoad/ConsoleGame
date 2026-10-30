#ifndef __WINDOW_PRINT_INFO_HXX__
#define __WINDOW_PRINT_INFO_HXX__

#include <ranges>
#include <vector>
#include <sstream>

#include "Color.Hxx"
#include "Vector2.Hxx"
#include "ANSIEscapeCode.Hxx"

namespace Game {

	struct WindowPrintBuffer {

	public:

		Vector2Size size;

		std::vector<char> characters;
		std::vector<Color> foregroundColors;
		std::vector<Color> backgroundColors;

		mutable std::ostringstream outputBuffer;

	public:
		
		WindowPrintBuffer(Vector2Size size) : size(size) {}

	public:

		void SetCharacter(Vector2Size position, char character);
		void SetForegroundColor(Vector2Size position, Color color);
		void SetBackgroundColor(Vector2Size position, Color color);

		char GetCharacter(Vector2Size position) const;
		Color GetForegroundColor(Vector2Size position) const;
		Color GetBackgroundColor(Vector2Size position) const;


	public:

		void Clear() noexcept;

		void Initialize(
			std::span<const char> characters,
			std::span<const Color> foregroundColors,
			std::span<const Color> backgroundColors
		) noexcept;

		std::ostringstream const& Build() const;

	};

}

#endif