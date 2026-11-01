#ifndef __ANSI_ESCAPE_CODE_HXX__
#define __ANSI_ESCAPE_CODE_HXX__

#include <string>
#include <format>

namespace Game {

	struct ANSI {

		inline static const std::string ANSIPrefix = "\x1b[";

		static std::string SetAlternateScreenBuffer(bool enable);

		static std::string SetForegroundColor(unsigned char r, unsigned char g, unsigned char b);
		static std::string SetBackgroundColor(unsigned char r, unsigned char g, unsigned char b);

	};

}

#endif