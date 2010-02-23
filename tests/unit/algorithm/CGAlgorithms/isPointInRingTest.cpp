// $Id: isPointInRingTest.cpp 1820 2006-09-06 16:54:23Z mloskot $
// 
// Test Suite for CGAlgorithms::isPointInRing() function

// TUT
#include <tut.h>
// STL
#include <string>
// GEOS
#include <geos/algorithm/CGAlgorithms.h>
#include <geos/geom/Polygon.h>
#include <geos/geom/Coordinate.h>
#include <geos/geom/Geometry.h>
#include <geos/io/WKTReader.h>

using namespace geos::algorithm;

namespace tut
{
    //
    // Test Group
    //

    struct test_ispointinring_data
    {
	    typedef std::auto_ptr<geos::geom::Geometry> GeomPtr;

        geos::io::WKTReader reader_;

        test_ispointinring_data() {}
    };

    typedef test_group<test_ispointinring_data> group;
    typedef group::object object;

    group test_ispointintring_group("geos::algorithm::CGAlgorithms::isPointInRing");

    //
    // Test Cases
    //

    // Test of point in simple Polygon
    template<>
    template<>
    void object::test<1>()
    {
        const std::string wkt("POLYGON ((0 0, 0 20, 20 20, 20 0, 0 0))");
		GeomPtr geom(reader_.read(wkt));

        geos::geom::Coordinate pt(10, 10);

        bool isInRing = CGAlgorithms::isPointInRing(pt, geom->getCoordinates());

        ensure_equals( true, isInRing );
    }

    // Test of point in bigger Polygon
    template<>
    template<>
    void object::test<2>()
    {
        const std::string wkt("POLYGON ((-40 80, -40 -80, 20 0, 20 -100, 40 40, \
                               80 -80, 100 80, 140 -20, 120 140, 40 180, 60 40, \
                               0 120, -20 -20, -40 80))");
		GeomPtr geom(reader_.read(wkt));

        geos::geom::Coordinate pt(0, 0);

        bool isInRing = CGAlgorithms::isPointInRing(pt, geom->getCoordinates());

        ensure_equals( true, isInRing );
    }


} // namespace tut
