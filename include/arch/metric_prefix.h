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

#include "functions.h"

namespace arch
{

namespace prefix
{

constexpr long double operator"" _tera(long double _value)
{
	return _value * pow(10.0, 12.0);
}

constexpr long double operator"" _giga(long double _value)
{
	return _value * pow(10.0, 9.0);
}

constexpr long double operator"" _mega(long double _value)
{
	return _value * pow(10.0, 6.0);
}

constexpr long double operator"" _kilo(long double _value)
{
	return _value * pow(10.0, 3.0);
}

constexpr long double operator"" _hecto(long double _value)
{
	return _value * pow(static_cast<long double>(10.0), static_cast<long double>(2.0));
}

constexpr long double operator"" _deca(long double _value)
{
	return _value * static_cast<long double>(10.0);
}

constexpr long double operator"" _deci(long double _value)
{
	return _value / static_cast<long double>(10.0);
}

constexpr long double operator"" _centi(long double _value)
{
	return _value / pow(static_cast<long double>(10.0), static_cast<long double>(2.0));
}

constexpr long double operator"" _milli(long double _value)
{
	return _value / pow(static_cast<long double>(10.0), static_cast<long double>(3.0));
}

constexpr long double operator"" _micro(long double _value)
{
	return _value / pow(static_cast<long double>(10.0), static_cast<long double>(6.0));
}

constexpr long double operator"" _nano(long double _value)
{
	return _value / pow(static_cast<long double>(10.0), static_cast<long double>(9.0));
}

constexpr long double operator"" _pico(long double _value)
{
	return _value / pow(static_cast<long double>(10.0), static_cast<long double>(12.0));
}

}

}

#ifdef USING_ARCH_PREFIX

using arch::prefix::operator"" _tera;
using arch::prefix::operator"" _giga;
using arch::prefix::operator"" _mega;
using arch::prefix::operator"" _kilo;
using arch::prefix::operator"" _hecto;
using arch::prefix::operator"" _deca;
using arch::prefix::operator"" _deci;
using arch::prefix::operator"" _centi;
using arch::prefix::operator"" _milli;
using arch::prefix::operator"" _micro;
using arch::prefix::operator"" _nano;
using arch::prefix::operator"" _pico;

#endif