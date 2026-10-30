#include "WindowPrintBuffer.Hxx"

namespace Game {

	void WindowPrintBuffer::SetCharacter(Vector2Size position, char character) {
		this->characters[position.y * this->size.x + position.x] = character;
	}

	void WindowPrintBuffer::SetForegroundColor(Vector2Size position, Color color) {
		this->foregroundColors[position.y * this->size.x + position.x] = color;
	}

	void WindowPrintBuffer::SetBackgroundColor(Vector2Size position, Color color) {
		this->backgroundColors[position.y * this->size.x + position.x] = color;
	}

	char WindowPrintBuffer::GetCharacter(Vector2Size position) const {
		return this->characters[position.y * this->size.x + position.x];
	}

	Color WindowPrintBuffer::GetForegroundColor(Vector2Size position) const {
		return this->foregroundColors[position.y * this->size.x + position.x];
	}

	Color WindowPrintBuffer::GetBackgroundColor(Vector2Size position) const {
		return this->backgroundColors[position.y * this->size.x + position.x];
	}

	void WindowPrintBuffer::Clear() noexcept {

		const size_t area = this->size.Area();
	
		this->characters.clear();
		this->characters.assign(area, ' ');

		this->foregroundColors.clear();
		this->foregroundColors.assign(area, Color::White);

		this->backgroundColors.clear();
		this->backgroundColors.assign(area, Color::Black);

	}

	void WindowPrintBuffer::Initialize(
		std::span<const char> characters,
		std::span<const Color> foregroundColors,
		std::span<const Color> backgroundColors
	) noexcept {

		this->characters.clear();
		this->characters.assign(characters.begin(), characters.end());

		this->foregroundColors.clear();
		this->foregroundColors.assign(foregroundColors.begin(), foregroundColors.end());

		this->backgroundColors.clear();
		this->backgroundColors.assign(backgroundColors.begin(), foregroundColors.end());

	}

	std::ostringstream const& WindowPrintBuffer::Build() const {

		this->outputBuffer.str("");
		this->outputBuffer.clear();

		Color previousForegroundColor = Color::One * -1.f;
		Color previousBackgroundColor = Color::One * -1.f;

		for (int y = 0; y < this->size.y; y++) {
			for (int x = 0; x < this->size.x; x++) {

				const auto position = this->size.x * y + x;
				const auto& foregroundColor = this->foregroundColors[position];
				const auto& backgroundColor = this->backgroundColors[position];

				if (previousForegroundColor != foregroundColor) {
					this->outputBuffer << ANSI::SetForegroundColor(foregroundColor);
					previousForegroundColor = foregroundColor;
				}

				if (previousBackgroundColor != backgroundColor) {
					this->outputBuffer << ANSI::SetBackgroundColor(backgroundColor);
					previousBackgroundColor = backgroundColor;
				}

				this->outputBuffer << this->characters[position];

			}
			if (y == this->size.y - 1) {
				this->outputBuffer << '\n';
			}
		}

		return this->outputBuffer;

	}

}
