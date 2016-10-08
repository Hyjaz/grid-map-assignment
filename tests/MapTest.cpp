//! @file
//! @brief Implementation file for the MapTest class
//!
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include "../src/entity/Map.h"
using namespace CppUnit;

//! Test Class for the Map class
class MapTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(MapTest);
	CPPUNIT_TEST(testMapCellFilled);
	CPPUNIT_TEST(testMapCellEmpty);
	CPPUNIT_TEST(testValidPath);
	CPPUNIT_TEST(testInvalidPath);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();
protected:
	void testMapCellFilled();
	void testMapCellEmpty();
	void testValidPath();
	void testInvalidPath();
private:
	Map *map;
};

//! cppunit registry creation
CPPUNIT_TEST_SUITE_REGISTRATION(MapTest);

//! method called before every test case in this test class
void MapTest::setUp()
{
	map = new Map();
}

//! method called after every test case in this test class
void MapTest::tearDown()
{
	delete map;
}

//! test method to test the isOccupied() method of the Map class
//! Test Case: the returned value should be true after filling the cell
//! Tested item: Map::isOccupied()
void MapTest::testMapCellFilled()
{
	// context: fill a cell
	map->fillCell(1, 1, 'a');
	//test: isOccupied() should return true after the cell having been filled
	CPPUNIT_ASSERT(true == map->isOccupied(1, 1));
}

//! test method to test the isOccupied() method of the Map class
//! Test Case: the returned value should be true after emptying the cell
//! Tested item: Map::isOccupied()
void MapTest::testMapCellEmpty()
{
	// context: make a cell empty
	map->fillCell(1, 1, ' ');
	// test: isOoccupied() should return false if the cell was not filled
	CPPUNIT_ASSERT(false == map->isOccupied(1, 1));
}

//! test method to test the validatePath() method of the Map class
//! Test Case: the returned value should be true if there is a valid path in the map
//! Tested item: Map::validatePath()
void MapTest::testValidPath()
{
	// context: create a map with a valid path
	// map as it is, is already valid

	// test: validatePath() should return true
	CPPUNIT_ASSERT(true == map->validate());
}

//! test method to test the validatePath() method of the Map class
//! Test Case: the returned value should be false if there is no valid path in the map
//! Tested item: Map::validatePath()
void MapTest::testInvalidPath()
{
	// context: create a map without a valid path: seperate entry and exit door by a wall
	for (int i = 0; i < map->getWidth(); i++) {
        map->setCellType(2,i, Cell::WALL);
	}

	// test: validatePath() should return false
	CPPUNIT_ASSERT(false == map->validate());
}
