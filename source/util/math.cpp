/**********************************************************************
 * $Id: math.cpp 1820 2006-09-06 16:54:23Z mloskot $
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2006 Refractions Research
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************/

#include "geos/util.h"
#include <cmath>

namespace geos {
namespace util { // geos.util

/*
 * Symmetric Rounding Algorithm  - equivalent to C99 round()
 */
double
sym_round(double val)
{
        double n;
        double f = fabs(modf(val, &n));
        if (val >= 0) {
                if (f < 0.5) {
                        return floor(val);
                } else if (f > 0.5) {
                        return ceil(val);
                } else {
                        return (n + 1.0);
                }
        } else {
                if (f < 0.5) {
                        return ceil(val);
                } else if (f > 0.5) {
                        return floor(val);
                } else {
                        return (n - 1.0);
                }
        }
}

/*
 * Asymmetric Rounding Algorithm  - equivalent to Java Math.round()
 */
double java_math_round(double val)
{
	double n;
	double f = fabs(modf(val, &n));
	
	if (val >= 0)
	{
		if (f < 0.5) {
			return floor(val);
		} else if (f > 0.5) {
			return ceil(val);
		} else {
			return (n + 1.0);
		}
	} else {
		if (f < 0.5) {
			return ceil(val);
		} else if (f > 0.5) {
			return floor(val);
		} else {
			return n;
		}
	}
} // java_math_round

/*
 * Implementation of rint() 
 */
double
rint_vc(double val)
{
	double n;
	double f=fabs(modf(val,&n));
	if (val>=0) {
		if (f<0.5) {
			return floor(val);
		} else if (f>0.5) {
			return ceil(val);
		} else {
			return(floor(n/2)==n/2)?n:n+1.0;
		}
	} else {
		if (f<0.5) {
			return ceil(val);
		} else if (f>0.5) {
			return floor(val);
		} else {
			return(floor(n/2)==n/2)?n:n-1.0;
		}
	}
}



} // namespace geos.util
} // namespace geos
