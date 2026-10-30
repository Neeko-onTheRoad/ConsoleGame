#include "ANSIEscapeCode.Hxx"

namespace Game {

	std::string ANSI::SetAlternateScreenBuffer(bool enable) {
		return ANSI::ANSIPrefix + (enable
			? "?1049h"
			: "?1049l"
		);
	}

	std::string ANSI::SetForegroundColor(Color const& color) {
		const auto byte = color.ToByteColor();
		return std::format("{}38;2;{};{};{}m",
			ANSI::ANSIPrefix,
			std::get<0>(byte),
			std::get<1>(byte),
			std::get<2>(byte)
		);
	}

	std::string ANSI::SetBackgroundColor(Color const& color) {
		const auto byte = color.ToByteColor();
		return std::format("{}48;2;{};{};{}m",
			ANSI::ANSIPrefix,
			std::get<0>(byte),
			std::get<1>(byte),
			std::get<2>(byte)
		);
	}

}
