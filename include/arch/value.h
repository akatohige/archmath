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

#include "dimension.h"

namespace arch
{

template <typename type>
class value final
{
public:
	typedef type value_type;
	typedef size_t size_type;
	typedef type* pointer;
	typedef const type* const_pointer;
	typedef type& reference;
	typedef const type& const_reference;

public:
	constexpr value(const dimension& _dim = dimension::dimensionless())
		: m_dimension(_dim)
	{
	}

	constexpr value(const dimension& _dim, const value_type& _quantity)
		: quantity(_quantity), dim(_dim)
	{
	}

	~value() = default;

	constexpr value& operator=(const value& _value)
	{
		quantity = _value.quantity;
		dim = _value.dim;
		return *this;
	}

	constexpr value& operator=(const value_type& _quantity)
	{
		quantity = _quantity;
		return *this;
	}

	constexpr value operator+(const value& _value) const
	{
		return value(dim, quantity + _value.quantity);
	}

	constexpr value operator+(const value_type& _quantity)
	{
		return value(dim, quantity + _quantity);
	}

	constexpr value& operator+=(const value& _value)
	{
		if (dim == _value.dim)
		{
			quantity += _value.quantity;
		}
		return *this;
	}

	constexpr value& operator+=(const value_type& _quantity)
	{
		quantity += _quantity;
		return *this;
	}

	constexpr value operator-(const value& _value) const
	{
		return value(dim, quantity - _value.quantity);
	}

	constexpr value operator-(const value_type& _quantity) const
	{
		return value(dim, quantity - _quantity);
	}

	constexpr value& operator-=(const value& _value)
	{
		if (dim == _value.dim)
		{
			quantity -= _value.quantity;
		}
		return *this;
	}

	constexpr value& operator-=(const value_type& _quantity)
	{
		quantity -= _quantity;
		return *this;
	}

	constexpr value operator*(const value& _value) const
	{
		return value(dim * _value.dim, quantity * _value.quantity);
	}

	constexpr value operator*(const value_type& _quantity) const
	{
		return value(dim, quantity * _quantity);
	}

	constexpr value& operator*=(const value& _value)
	{
		quantity *= _value.quantity;
		dim *= _value.dim;
		return *this;
	}

	constexpr value& operator*=(const value_type& _quantity)
	{
		quantity *= _quantity;
		return *this;
	}

	constexpr value operator/(const value& _value) const
	{
		return value(dim / _value.dim, quantity / _value.quantity);
	}

	constexpr value operator/(const value_type& _quantity) const
	{
		return value(dim, quantity / _quantity);
	}

	constexpr value& operator/=(const value& _value)
	{
		quantity /= _value.quantity;
		dim /= _value.dim;
		return *this;
	}

	constexpr value& operator/=(const value_type& _quantity)
	{
		quantity /= quantity;
		return *this;
	}

	constexpr bool operator==(const value& _value) const
	{
		return quantity == _value.quantity && dim == _value.dim;
	}

	constexpr bool operator==(const value_type& _quantity) const
	{
		return quantity == _quantity;
	}

	constexpr bool operator!=(const value& _value) const
	{
		return quantity != _value.quantity || dim != _value.dim;
	}

	constexpr bool operator!=(const value_type& _quantity) const
	{
		return quantity != _quantity;
	}

public:
	value_type quantity;
	dimension dim;
};

template<typename type, typename char_t> inline std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& _os, const value<type>& _value)
{
	_os << _value.quantity << '[' << _value.dim << ']';

	return _os;
}

}