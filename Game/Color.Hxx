#ifndef __COLOR_HXX__
#define __COLOR_HXX__

#include <format>
#include <string>
#include <functional>

#include "Math.Hxx"

namespace Game {

	struct Color { // TODO: Make Byte Color

	public:

		static constexpr float LuminanceR = 0.2126f;
		static constexpr float LuminanceG = 0.7152f;
		static constexpr float LuminanceB = 0.0722f;

		static const Color Zero;
		static const Color One;

	public:

		float r = 0.f;
		float g = 0.f;
		float b = 0.f;

	public:

		Color() noexcept = default;
		Color(float r, float g, float b) noexcept : r(r), g(g), b(b) {}

		Color(unsigned char r, unsigned char g, unsigned char b) noexcept :
			r(static_cast<float>(r) / 255.f),
			g(static_cast<float>(g) / 255.f),
			b(static_cast<float>(b) / 255.f) {}

	public:

		void Clamp() noexcept;

	public:

		Color Clamped() const noexcept;
		Color Grayscale() const noexcept;

		std::string ToString() const;
		std::string ToHEXString() const;
		std::tuple<unsigned char, unsigned char, unsigned char> ToByteColor() const;

		std::string ToANSIForegroundString() const;
		std::string ToANSIBackgroundString() const;

		Color Invoke(std::function<float(float)> const& function) const;

	public:

		static Color Lerp(Color const& from, Color const& to, float t) noexcept;

	public:

		friend bool operator==(Color const& left, Color const& right) noexcept;
		friend bool operator!=(Color const& left, Color const& right) noexcept;

		friend Color operator+(Color const& left, Color const& right) noexcept;
		friend Color operator-(Color const& left, Color const& right) noexcept;

		friend Color operator*(float scaler, Color const& color) noexcept;
		friend Color operator*(Color const& color, float scaler) noexcept;
		friend Color operator/(Color const& color, float scaler) noexcept;

	public:

		static const Color Black;
		static const Color DarkGray;
		static const Color Gray;
		static const Color LightGray;
		static const Color White;

		static const Color Red;
		static const Color Green;
		static const Color Blue;

		static const Color Yellow;
		static const Color Magenta;
		static const Color Cyan;

	};

}

#endif