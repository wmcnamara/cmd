#pragma once

template <typename T>
class Vector3
{
	public:
		Vector3(T x, T y, T z) : x(_x), y(_y), z(_z) {}

		void operator = (const Vector3& vec) { _x = vec._x; _y = vec._y }

		//Getters
		const T& x() { return _x; }
		const T& y() { return _y; }
		const T& z() { return _z; }

		//Setters
		const T& x(T val) { return _x = val; }
		const T& y(T val) { return _y = val; }
		const T& z(T val) { return _z = val; }

	private:
		T _x, _y, _z;		
};