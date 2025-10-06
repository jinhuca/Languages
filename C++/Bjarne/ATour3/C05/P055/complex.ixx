export module complex;

import std;

namespace P055
{
	export class complex																				// concrete class type
	{
	private:
		double re, im;																						// representation: two doubles
	public:
		complex(double r, double i) : re(r), im(i) {}							// construct complex from two scalars
		complex(double r) : re { r }, im { 0 } {}                 // construct complex from one scalar
		complex() : re { 0 }, im { 0 } {}                         // default complex: {0, 0}
		complex(const complex &z) : re { z.re }, im { z.im } {}   // copy constructor

		double real() const { return re; }												// get real
		void real(double d) { re = d; }														// set real
		double imag() const { return im; }												// get imagine
		void imag(double d) { im = d; }														// set imagine

		complex &operator+=(const complex z)											// define operator +=
		{
			re += z.re;
			im += z.im;
			return *this;
		}

		complex &operator-=(const complex z)											// define operator -=
		{
			re -= z.re;
			im -= z.im;
			return *this;
		}

		complex operator+(const complex &) const;									// defined out-of-class somewhere
		complex operator-(const complex &) const;
		complex operator*(const complex &) const;
		complex operator/(const complex &) const;
		complex operator*=(const complex &) const;
		complex operator/=(const complex &) const;
		bool operator==(const complex &) const;
		bool operator!=(const complex &) const;
		complex operator-() const;
	};

	export std::ostream &operator<<(std::ostream &os, const complex &rhs);
}