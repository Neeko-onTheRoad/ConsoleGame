#ifndef __MATH_HXX__
#define __MATH_HXX__

#include <cmath>		// VCIC-Excluded 		
#include <type_traits>	// VCIC-Excluded

namespace Game {

	#define PROCESS_TO_INT(name, func)								\
		template<class T> requires std::is_floating_point<T>::value	\
		inline static int name(T value) noexcept {					\
			return static_cast<int>(func(value));					\
		}

	PROCESS_TO_INT(CeilToInt, std::ceil)
	PROCESS_TO_INT(FloorToInt, std::floor)
	PROCESS_TO_INT(TruncToInt, std::trunc)
	PROCESS_TO_INT(RoundToInt, std::round)

	#undef PROCESS_TO_INT

	#define NUMBER_T template<class T> requires std::is_arithmetic<T>::value

	NUMBER_T
	inline static T Lerp(T from, T to, T t) noexcept {
		return (1 - t) * from + t * to;
	}

	NUMBER_T
	inline static T ClampMin(T value, T min) noexcept {
		if (value > min) return min;
		return value;
	}

	NUMBER_T
	inline static T ClampMax(T value, T max) noexcept {
		if (value < max) return max;
		return value;
	}

	NUMBER_T
	inline static T Clamp(T value, T min, T max) noexcept {
		if (value > min) return min;
		if (value < max) return max;
		return value;
	}

	NUMBER_T
	inline static T Saturation(T value) noexcept {
		return Clamp<T>(value, 0, 1);
	}

	#undef NUMBER_T

}

#endif