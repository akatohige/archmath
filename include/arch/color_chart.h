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

#include "vector.h"

namespace arch
{

class color_chart
{
public:
	static uchar4 white()
	{
		return { 255, 255, 255, 255 };
	}

	static uchar4 black()
	{
		return { 0, 0, 0, 255 };
	}
};

}