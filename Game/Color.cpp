#include "Color.Hxx"

namespace Game {

	const Color Color::Zero = { 0.f, 0.f, 0.f };
	const Color Color::One = { 1.f, 1.f, 1.f };

	const Color Color::Black		= Color::Lerp(Color::Zero, Color::One, 0.f / 4.f);
	const Color Color::DarkGray		= Color::Lerp(Color::Zero, Color::One, 1.f / 4.f);
	const Color Color::Gray			= Color::Lerp(Color::Zero, Color::One, 2.f / 4.f);
	const Color Color::LightGray	= Color::Lerp(Color::Zero, Color::One, 3.f / 4.f);
	const Color Color::White		= Color::Lerp(Color::Zero, Color::One, 4.f / 4.f);

	const Color Color::Red		= { 1.f, 0.f, 0.f };
	const Color Color::Green	= { 0.f, 1.f, 0.f };
	const Color Color::Blue		= { 0.f, 0.f, 1.f };

	const Color Color::Yellow	= Color::Red + Color::Green;
	const Color Color::Magenta	= Color::Red + Color::Blue;
	const Color Color::Cyan		= Color::Green + Color::Blue;

	void Color::Clamp() noexcept {
		this->r = Saturation(this->r);
		this->g = Saturation(this->g);
		this->b = Saturation(this->b);
	}

    Color Color::Clamped() const noexcept {
		return {
			Saturation(this->r),
			Saturation(this->g),
			Saturation(this->b)
		};
    }

	Color Color::Grayscale() const noexcept {
		return Color::One * (
			this->r * Color::LuminanceR +
			this->g * Color::LuminanceG +
			this->b * Color::LuminanceB
		);
	}

	std::string Color::ToString() const {
		return std::format("({}, {}, {})", this->r, this->g, this->b);
	}

	std::string Color::ToHEXString() const {
		return std::format(
			"#{:02X}{:02X}{:02X}",
			static_cast<unsigned char>(this->r * 255.f),
			static_cast<unsigned char>(this->g * 255.f),
			static_cast<unsigned char>(this->b * 255.f)
		);
	}

	std::tuple<unsigned char, unsigned char, unsigned char> Color::ToByteColor() const {
		return {
			static_cast<unsigned char>(this->r * 255.f),
			static_cast<unsigned char>(this->g * 255.f),
			static_cast<unsigned char>(this->b * 255.f)
		};
	}

	std::string Color::ToANSIForegroundString() const {
		return std::string(); // TODO
	}

	std::string Color::ToANSIBackgroundString() const {
		return std::string(); // TODO
	}

    Color Color::Invoke(std::function<float(float)> const& function) const {
		return {
			function(this->r),
			function(this->g),
			function(this->b)
		};
    }

	Color Color::Lerp(Color const& from, Color const& to, float t) noexcept {
		return (1.f - t) * from + t * to;
	}

	bool operator==(Color const& left, Color const& right) noexcept {
		return
			left.r == right.r &&
			left.g == right.g &&
			left.b == right.b;
	}

	bool operator!=(Color const& left, Color const& right) noexcept {
		return
			left.r != right.r ||
			left.g != right.g ||
			left.b != right.b;
	}

	Color operator+(Color const& left, Color const& right) noexcept {
		return {
			left.r + right.r,
			left.g + right.g,
			left.b + right.b
		};
	}

	Color operator-(Color const& left, Color const& right) noexcept {
		return {
			left.r - right.r,
			left.g - right.g,
			left.b - right.b
		};
	}

	Color operator*(float scaler, Color const& color) noexcept {
		return color * scaler;
	}

	Color operator*(Color const& color, float scaler) noexcept {
		return {
			color.r * scaler,
			color.g * scaler,
			color.b * scaler
		};
	}

	Color operator/(Color const& color, float scaler) noexcept {
		return {
			color.r / scaler,
			color.g / scaler,
			color.b / scaler
		};
	}

}

