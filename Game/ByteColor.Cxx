#include "ByteColor.Hxx"

namespace Game {

	std::string ByteColor::ToString() const {
		return std::format("({}, {}, {})", this->r, this->g, this->b);
	}

	std::string ByteColor::ToHEXString() const {
		return std::format("#{:02X}{:02X}{:02X}", this->r, this->g, this->b);
	}

	std::string ByteColor::ToANSIForegroundString() const {
		return ANSI::SetForegroundColor(this->r, this->g, this->b);
	}

	std::string ByteColor::ToANSIBackgroundString() const {
		return ANSI::SetBackgroundColor(this->r, this->g, this->b);
	}

	bool operator==(ByteColor const& left, ByteColor const& right) noexcept {
		return
			left.r == right.r &&
			left.g == right.g &&
			left.b == right.b;
	}

	bool operator!=(ByteColor const& left, ByteColor const& right) noexcept {
		return
			left.r != right.r ||
			left.g != right.g ||
			left.b != right.b;
	}

}