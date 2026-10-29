#ifndef __VECTOR2_BASE_HXX__
#define __VECTOR2_BASE_HXX__

#include <cmath>
#include <string>
#include <iostream>

#include "Vector2Swizzle.Hxx"

namespace Game {

	template<class T> requires std::is_arithmetic<T>::value
	struct Vector2Base {

	public:
		
		T x;
		T y;

	public:
	
		const static Vector2Base<T> Zero;
		const static Vector2Base<T> One;

	public:
		
		Vector2Base() : Vector2Base(0, 0) {}
		Vector2Base(T x, T y) : x(x), y(y) {}

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

		std::string ToString() const noexcept {
			return std::format("({}, {})", this->x, this->y);
		}

	public:

		void Normalize() noexcept {
			const auto magnitude = this->Magnitude();
			x /= magnitude;
			y /= magnitude;
		}

	public:

		static float Dot(Vector2Base<T> const& left, Vector2Base<T> const& right) noexcept {
			return left.x * right.x + left.y * right.y;
		}

		static float Cross(Vector2Base<T> const& left, Vector2Base<T> const& right) noexcept {
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