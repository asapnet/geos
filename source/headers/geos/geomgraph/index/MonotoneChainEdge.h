/**********************************************************************
 * $Id: MonotoneChainEdge.h 1820 2006-09-06 16:54:23Z mloskot $
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2005-2006 Refractions Research Inc.
 * Copyright (C) 2001-2002 Vivid Solutions Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************/

#ifndef GEOS_GEOMGRAPH_INDEX_MONOTONECHAINEDGE_H
#define GEOS_GEOMGRAPH_INDEX_MONOTONECHAINEDGE_H

#include <geos/geom/Envelope.h> // for composition

// Forward declarations
namespace geos {
	namespace geom {
		class CoordinateSequence;
	}
	namespace geomgraph {
		class Edge;
		namespace index {
			class SegmentIntersector;
		}
	}
}

namespace geos {
namespace geomgraph { // geos::geomgraph
namespace index { // geos::geomgraph::index

class MonotoneChainEdge {
public:
	//MonotoneChainEdge();
	~MonotoneChainEdge();
	MonotoneChainEdge(Edge *newE);
	const geom::CoordinateSequence* getCoordinates();
	std::vector<int>& getStartIndexes();
	double getMinX(int chainIndex);
	double getMaxX(int chainIndex);

	void computeIntersects(const MonotoneChainEdge &mce,
		SegmentIntersector &si);

	void computeIntersectsForChain(int chainIndex0,
		const MonotoneChainEdge &mce, int chainIndex1,
		SegmentIntersector &si);

protected:
	Edge *e;
	const geom::CoordinateSequence* pts; // cache a reference to the coord array, for efficiency
	// the lists of start/end indexes of the monotone chains.
	// Includes the end point of the edge as a sentinel
	std::vector<int> startIndex;
	// these envelopes are created once and reused
	geom::Envelope env1;
	geom::Envelope env2;
private:
	void computeIntersectsForChain(int start0, int end0,
		const MonotoneChainEdge &mce,
		int start1, int end1,
		SegmentIntersector &ei);
};



} // namespace geos.geomgraph.index
} // namespace geos.geomgraph
} // namespace geos

#endif

/**********************************************************************
 * $Log$
 * Revision 1.1  2006/03/14 12:55:55  strk
 * Headers split: geomgraphindex.h, nodingSnapround.h
 *
 **********************************************************************/

