#ifndef __WINDOW_PRINT_INFO_HXX__
#define __WINDOW_PRINT_INFO_HXX__

#include <ranges>
#include <vector>

#include "Color.Hxx"
#include "Vector2.Hxx"

namespace Game {

	struct WindowPrintInfo {

	public:

		Vector2Unsigned size;

		std::vector<char> characters;
		std::vector<Color> foregroundColors;
		std::vector<Color> backgroundColors;

	public:
		
		WindowPrintInfo(Vector2Unsigned size) : size(size) {}
		WindowPrintInfo(
			Vector2Unsigned size,
			std::span<const char> characters,
			std::span<const Color> foregroundColors,
			std::span<const Color> backgroundColors
		) noexcept
			: size(size)
			, characters(characters.begin(), characters.end())
			, foregroundColors(foregroundColors.begin(), foregroundColors.end())
			, backgroundColors(backgroundColors.begin(), foregroundColors.end()) {}

	public:

		void SetCharacter(Vector2Unsigned position, char target);
		void SetForegroundColor(Vector2Unsigned position, Color color);
		void SetBackgroundColor(Vector2Unsigned position, Color color);

		char GetCharacter(Vector2Unsigned position) const;
		Color GetForegroundColor(Vector2Unsigned position) const;
		Color GetBackgroundColor(Vector2Unsigned position) const;


	public:

		std::string Build() const noexcept;

	};

}

#endif