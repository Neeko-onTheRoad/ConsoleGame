#include "Color.Hxx"

namespace Game {

	const Color Color::Zero = { 0.f, 0.f, 0.f };
	const Color Color::One = { 1.f, 1.f, 1.f };

	void Color::Clamp() noexcept {
		r = Saturation(r);
		g = Saturation(g);
		b = Saturation(b);
	}

    Color Color::Clamped() const noexcept {
		return {
			Saturation(r),
			Saturation(g),
			Saturation(b)
		};
    }

	Color Color::Grayscale() const noexcept {
		return Color::One * (
			r * Color::LuminanceR +
			g * Color::LuminanceG +
			b * Color::LuminanceB
		);
	}

	std::string Color::ToString() const {
		return std::format("({}, {}, {})", r, g, b);
	}

	std::string Color::ToHEXString() const {
		return std::format(
			"#{:02X}{:02X}{:02X}",
			static_cast<signed char>(r * 255.f),
			static_cast<signed char>(g * 255.f),
			static_cast<signed char>(b * 255.f)
		);
	}

	std::tuple<signed char, signed char, signed char> Color::ToByteColor() const {
		return {
			static_cast<signed char>(r * 255.f),
			static_cast<signed char>(g * 255.f),
			static_cast<signed char>(b * 255.f)
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
			function(r),
			function(g),
			function(b)
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

	const Color Black		= Color::Lerp(Color::Zero, Color::One, 0.f / 4.f);
	const Color DarkGray	= Color::Lerp(Color::Zero, Color::One, 1.f / 4.f);
	const Color Gray		= Color::Lerp(Color::Zero, Color::One, 2.f / 4.f);
	const Color LightGray	= Color::Lerp(Color::Zero, Color::One, 3.f / 4.f);
	const Color White		= Color::Lerp(Color::Zero, Color::One, 4.f / 4.f);

	const Color Red			= { 1.f, 0.f, 0.f };
	const Color Green		= { 0.f, 1.f, 0.f };
	const Color Blue		= { 0.f, 0.f, 1.f };

	const Color Yellow		= Color::Red + Color::Green;
	const Color Magenta		= Color::Red + Color::Blue;
	const Color Cyan		= Color::Green + Color::Blue;

}

