#include "ANSIEscapeCode.Hxx"

namespace Game {

	std::string ANSI::SetAlternateScreenBuffer(bool enable) {
		return ANSI::ANSIPrefix + (enable
			? "?1049h"
			: "?1049l"
		);
	}

	std::string ANSI::SetForegroundColor(unsigned char r, unsigned char g, unsigned char b) {
		return std::format("{}38;2;{};{};{}m", ANSI::ANSIPrefix, r, g, b);
	}

	std::string ANSI::SetBackgroundColor(unsigned char r, unsigned char g, unsigned char b) {
		return std::format("{}48;2;{};{};{}m", ANSI::ANSIPrefix, r, g, b);
	}


}
