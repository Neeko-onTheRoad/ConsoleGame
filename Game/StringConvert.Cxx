#include "StringConvert.Hxx"

namespace Game {

	std::string WCharPToString(const wchar_t* wstr) {

		if (!wstr) return "";

		size_t length = 0;
		wcstombs_s(&length, nullptr, 0, wstr, _TRUNCATE);

		if (length == 0) return "";

		std::vector<char> buffer(length);
		wcstombs_s(&length, buffer.data(), length, wstr, _TRUNCATE);

		return std::string(buffer.data());

	}

}