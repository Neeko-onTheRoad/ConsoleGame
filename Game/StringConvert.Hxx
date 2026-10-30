#ifndef __STRING_CONVERT_HXX__
#define __STRING_CONVERT_HXX__

#include <string>
#include <vector>

namespace Game {

	inline static std::string WCharPToString(const wchar_t* wstr) {

		if (!wstr) return "";

		size_t length = 0;
		wcstombs_s(&length, nullptr, 0, wstr, _TRUNCATE);

		if (length == 0) return "";

		std::vector<char> buffer(length);
		wcstombs_s(&length, buffer.data(), length, wstr, _TRUNCATE);

		return std::string(buffer.data());

	}

}

#endif