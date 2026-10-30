#ifndef __VECTOR2_BASE_HXX__
#define __VECTOR2_BASE_HXX__

#include <format> // VCIC-Excluded 
#include <string>
#include <iostream>
#include <functional>
#include <type_traits>

#include "Math.Hxx" // VCIC-Excluded 
#include "Vector2Swizzle.Hxx"

namespace Game {

	template<class T> requires std::is_arithmetic<T>::value
	struct Vector2Base {

	public:

		using ValueType = T;

	public:
		
		T x = 0;
		T y = 0;

	public:
	
		const static Vector2Base<T> Zero;
		const static Vector2Base<T> One;

	public:
		
		Vector2Base() noexcept = default;
		Vector2Base(T x, T y) noexcept : x(x), y(y) {}

	public:

		T MagnitudeSqr() const noexcept {
			return x * x + y * y;
		}

		T Magnitude() const noexcept requires std::is_floating_point<T>::value {
			return std::sqrt(this->MagnitudeSqr());
		}

		Vector2Base<T> Normalized() const noexcept requires std::is_floating_point<T>::value {

			const auto magnitude = this->Magnitude();

			if (magnitude == 0) return this->Zero;
			return *this / magnitude;

		}

		Vector2Base<T> Swizzle(Vector2Swizzle swizzleMethod) const noexcept {
			return {
				static_cast<int>(swizzleMethod) & 0x10
					? this->y
					: this->x,
				static_cast<int>(swizzleMethod) & 0x01
					? this->y
					: this->x
			};
		}

		std::string ToString() const {
			return std::format("({}, {})", this->x, this->y);
		}

		template<class TOther> requires std::is_arithmetic<TOther>::value
		Vector2Base<TOther> Cast() const noexcept {
			return {
				static_cast<TOther>(x),
				static_cast<TOther>(y)
			};
		}

		template<class TOther> requires std::is_arithmetic<TOther>::value
		Vector2Base<TOther> Invoke(std::function<TOther(T)> const& function) const {
			return {
				function(x),
				function(y)
			};
		}

	public:

		void Normalize() noexcept requires std::is_floating_point<T>::value {

			const auto magnitude = this->Magnitude();
			if (magnitude == 0)	return;

			x /= magnitude;
			y /= magnitude;

		}

	public:

		static T Dot(Vector2Base<T> const& left, Vector2Base<T> const& right) noexcept {
			return left.x * right.x + left.y * right.y;
		}

		static T Cross(Vector2Base<T> const& left, Vector2Base<T> const& right) noexcept {
			return left.x * right.y - right.y * left.x;
		}

		static Vector2Base<T> Lerp(
			Vector2Base<T> const& from,
			Vector2Base<T> const& to,
			T t
		) noexcept requires std::is_floating_point<T>::value {
			return (1 - t) * from + t * to;
		}

	public:

		friend Vector2Base<T> operator*(Vector2Base<T> const& vector, T scaler) noexcept {
			return {
				vector.x * scaler,
				vector.y * scaler
			};
		}

		friend Vector2Base<T> operator*(T scaler, Vector2Base<T> const& vector) noexcept {
			return vector * scaler;
		}
		
		friend Vector2Base<T> operator/(Vector2Base<T> const& vector, T scaler) noexcept {
			return {
				vector.x / scaler,
				vector.y / scaler
			};
		}

		friend Vector2Base<T> operator+(Vector2Base<T> const& left, Vector2Base<T> const& right) noexcept {
			return {
				left.x + right.x,
				left.y + right.y
			};
		}

		friend Vector2Base<T> operator-(Vector2Base<T> const& left, Vector2Base<T> const& right) noexcept {
			return {
				left.x - right.x,
				left.y - right.y
			};
		}

		friend bool operator==(Vector2Base<T> const& left, Vector2Base<T> const& right) noexcept {
			return left.x == right.x && left.y == right.y;
		}

		friend bool operator!=(Vector2Base<T> const& left, Vector2Base<T> const& right) noexcept {
			return left.x != right.x || left.y != right.y;
		}

	};
	
	template<class T> requires std::is_arithmetic<T>::value
	const Vector2Base<T> Vector2Base<T>::Zero = { 0, 0 };

	template<class T> requires std::is_arithmetic<T>::value
	const Vector2Base<T> Vector2Base<T>::One = { 1, 1 };

	template<class T> requires std::is_arithmetic<T>::value
	std::ostream& operator<<(std::ostream& stream, Vector2Base<T> const& vector) {
		stream << vector.ToString();
		return stream;
	}

}

#endif