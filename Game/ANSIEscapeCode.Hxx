#ifndef __ANSI_ESCAPE_CODE_HXX__
#define __ANSI_ESCAPE_CODE_HXX__

#include <string>
#include <format>

#include "Color.Hxx"

namespace Game {

	struct ANSI {

		inline static const std::string ANSIPrefix = "\x1b[";

		static std::string SetAlternateScreenBuffer(bool enable);
		static std::string SetForegroundColor(Color const& color);
		static std::string SetBackgroundColor(Color const& color);

	};

}

#endif