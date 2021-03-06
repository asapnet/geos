/**********************************************************************
 * $Id
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2006 Refractions Research Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 *
 **********************************************************************/

#ifndef GEOS_GEOM_PREP_PREPAREDPOLYGONCONTAINS_H
#define GEOS_GEOM_PREP_PREPAREDPOLYGONCONTAINS_H

#include <geos/geom/prep/AbstractPreparedPolygonContains.h> // inherited

// forward declarations
namespace geos {
	namespace geom { 
		class Geometry;

		namespace prep { 
			class PreparedPolygon;
		}
	}
}

namespace geos {
namespace geom { // geos::geom
namespace prep { // geos::geom::prep

class PreparedPolygonContains : public AbstractPreparedPolygonContains 
{
private:
protected:
	/**
	* Computes the full topological <tt>contains</tt> predicate.
	* Used when short-circuit tests are not conclusive.
	* 
	* @param geom the test geometry
	* @return true if this prepared polygon contains the test geometry
	*/
	bool fullTopologicalPredicate( const geom::Geometry * geom);

public:
	/**
	 * Computes the </tt>contains</tt> predicate between a {@link PreparedPolygon}
	 * and a {@link Geometry}.
	 * 
	 * @param prep the prepared polygon
	 * @param geom a test geometry
	 * @return true if the polygon contains the geometry
	 */
	static bool contains( const PreparedPolygon * const prep, const geom::Geometry * geom)
	{
		PreparedPolygonContains polyInt( prep);
		return polyInt.contains( geom);
	}

	/**
	 * Creates an instance of this operation.
	 * 
	 * @param prepPoly the PreparedPolygon to evaluate
	 */
	PreparedPolygonContains( const PreparedPolygon * const prepPoly)
	:	AbstractPreparedPolygonContains( prepPoly)
	{ }
		
	/**
	 * Tests whether this PreparedPolygon <tt>contains</tt> a given geometry.
	 * 
	 * @param geom the test geometry
	 * @return true if the test geometry is contained
	 */
	bool contains( const geom::Geometry * geom)
	{
		return eval( geom);
	}
	
};

} // geos::geom::prep
} // geos::geom
} // geos

#endif // GEOS_GEOM_PREP_PREPAREDPOLYGONCONTAINS_H
/**********************************************************************
 * $Log$
 **********************************************************************/

