//=================================================================================//
//                                                                                 //
//  ArchMath                                                                       //
//                                                                                 //
//  Copyright (C) 2011-2017 Terry                                                  //
//                                                                                 //
//  This file is a portion of the ArchMath. It is distributed under the MIT	       //
//  License, available in the root of this distribution and at the following URL.  //
//  http://opensource.org/licenses/mit-license.php                                 //
//                                                                                 //
//=================================================================================//

#pragma once

#include <iostream>
#include <string>

namespace arch
{

class dimension final
{
public:
	constexpr dimension(int _M = 0, int _L = 0, int _T = 0, int _I = 0, int _O = 0, int _N = 0, int _J = 0)
		: M(_M), L(_L), T(_T), I(_I), O(_O), N(_N), J(_J)
	{
	}

	constexpr dimension& operator=(const dimension& _dim)
	{
		M = _dim.M;
		L = _dim.L;
		T = _dim.T;
		I = _dim.I;
		O = _dim.O;
		N = _dim.N;
		J = _dim.J;
		return *this;
	}

	constexpr dimension operator*(const dimension& _dim) const
	{
		int _M = M + _dim.M;
		int _L = L + _dim.L;
		int _T = T + _dim.T;
		int _I = I + _dim.I;
		int _O = O + _dim.O;
		int _N = N + _dim.N;
		int _J = J + _dim.J;
		return dimension(_M, _L, _T, _I, _O, _N, _J);
	}

	constexpr dimension& operator*=(const dimension& _dim)
	{
		M += _dim.M;
		L += _dim.L;
		T += _dim.T;
		I += _dim.I;
		O += _dim.O;
		N += _dim.N;
		J += _dim.J;
		return *this;
	}

	constexpr dimension operator/(const dimension& _dim) const
	{
		int _M = M - _dim.M;
		int _L = L - _dim.L;
		int _T = T - _dim.T;
		int _I = I - _dim.I;
		int _O = O - _dim.O;
		int _N = N - _dim.N;
		int _J = J - _dim.J;
		return dimension(_M, _L, _T, _I, _O, _N, _J);
	}

	constexpr dimension& operator/=(const dimension& _dim)
	{
		M -= _dim.M;
		L -= _dim.L;
		T -= _dim.T;
		I -= _dim.I;
		O -= _dim.O;
		N -= _dim.N;
		J -= _dim.J;
		return *this;
	}

	constexpr bool operator==(const dimension& _dim) const
	{
		return (M == _dim.M && L == _dim.L && T == _dim.T && I == _dim.I && O == _dim.O && N == _dim.N && J == _dim.J);
	}

	constexpr bool operator!=(const dimension& _dim) const
	{
		return (M != _dim.M || L != _dim.L || T != _dim.T || I != _dim.I || O != _dim.O || N != _dim.N || J != _dim.J);
	}

public:
	static constexpr dimension dimensionless()
	{
		return dimension(0, 0, 0, 0, 0, 0);
	}

	static constexpr dimension mass()
	{
		return dimension(1, 0, 0, 0, 0, 0, 0);
	}

	static constexpr dimension wavenumber()
	{
		return dimension(0, -1, 0, 0, 0, 0, 0);
	}

	static constexpr dimension length()
	{
		return dimension(0, 1, 0, 0, 0, 0, 0);
	}

	static constexpr dimension area()
	{
		return dimension(0, 2, 0, 0, 0, 0, 0);
	}

	static constexpr dimension volume()
	{
		return dimension(0, 3, 0, 0, 0, 0, 0);
	}

	static constexpr dimension time()
	{
		return dimension(0, 0, 1, 0, 0, 0, 0);
	}

	static constexpr dimension electric_current()
	{
		return dimension(0, 0, 0, 1, 0, 0, 0);
	}

	static constexpr dimension temperature()
	{
		return dimension(0, 0, 0, 0, 1, 0, 0);
	}

	static constexpr dimension amount_of_substance()
	{
		return dimension(0, 0, 0, 0, 0, 1, 0);
	}

	static constexpr dimension luminous_intensity()
	{
		return dimension(0, 0, 0, 0, 0, 0, 1);
	}

	static constexpr dimension frequency()
	{
		return dimension(0, 0, -1, 0, 0, 0, 0);
	}

	static constexpr dimension velocity()
	{
		return dimension(0, 1, -1, 0, 0, 0, 0);
	}

	static constexpr dimension acceleration()
	{
		return dimension(0, 1, -2, 0, 0, 0, 0);
	}

	static constexpr dimension energy()
	{
		return dimension(1, 2, -2, 0, 0, 0, 0);
	}

	static constexpr dimension energy_density()
	{
		return dimension(1, -1, -2, 0, 0, 0, 0);
	}

	static constexpr dimension entropy()
	{
		return dimension(1, 2, -2, 0, -1, 0, 0);
	}

	static constexpr dimension electric_potential()
	{
		return dimension(1, 2, -3, -1, 0, 0, 0);
	}

	static constexpr dimension electrical_resistance()
	{
		return dimension(1, 2, -3, -2, 0, 0, 0);
	}

	static constexpr dimension force()
	{
		return dimension(1, 1, -2, 0, 0, 0, 0);
	}

	static constexpr dimension impulse()
	{
		return dimension(1, 1, -1, 0, 0, 0, 0);
	}

	static constexpr dimension density()
	{
		return dimension(1, -3, 0, 0, 0, 0, 0);
	}

	static constexpr dimension specific_volume()
	{
		return dimension(-1, 3, 0, 0, 0, 0, 0);
	}
	

public:
	int M;	/// Mass[kg]
	int L;	/// Length[m]
	int T;	/// Time[s]
	int I;	/// Electric current[A]
	int O;	/// Temperature[K]
	int N;	/// Amount of substance[mol]
	int J;	/// Luminous intensity[cd]
};

template<typename char_t> inline std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& _os, const dimension& _dim)
{
	if (_dim.M != 0)
	{
		_os << (_dim.M == 1 ? "kg" : "kg^" + std::to_string(_dim.M));
	}

	if (_dim.L != 0)
	{
		_os << (_dim.L == 1 ? "m" : "m^" + std::to_string(_dim.L));
	}

	if (_dim.T != 0)
	{
		_os << (_dim.T == 1 ? "s" : "s^" + std::to_string(_dim.T));
	}

	if (_dim.I != 0)
	{
		_os << (_dim.I == 1 ? "A" : "A^" + std::to_string(_dim.I));
	}

	if (_dim.O != 0)
	{
		_os << (_dim.O == 1 ? "K" : "K^" + std::to_string(_dim.O));
	}

	if (_dim.N != 0)
	{
		_os << (_dim.N == 1 ? "mol" : "mol^" + std::to_string(_dim.N));
	}

	if (_dim.J != 0)
	{
		_os << (_dim.J == 1 ? "cd" : "cd^" + std::to_string(_dim.J));
	}

	return _os;
}

}