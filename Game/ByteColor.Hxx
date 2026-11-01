#ifndef __BYTE_COLOR_HXX__
#define __BYTE_COLOR_HXX__

#include <string>
#include <iostream>

#include "ANSIEscapeCode.Hxx"

namespace Game {

	struct ByteColor {

	public:

		unsigned char r = 0;
		unsigned char g = 0;
		unsigned char b = 0;

	public:

		ByteColor() = default;
		ByteColor(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}

	public:

		std::string ToString() const;
		std::string ToHEXString() const;

		std::string ToANSIForegroundString() const;
		std::string ToANSIBackgroundString() const;

	public:

		friend bool operator==(ByteColor const& left, ByteColor const& right) noexcept;
		friend bool operator!=(ByteColor const& left, ByteColor const& right) noexcept;

	};

	std::ostream& operator<<(std::ostream& stream, ByteColor const& color) {
		stream << color.ToString();
		return stream;
	}

}

#endif