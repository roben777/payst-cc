/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// \file Testcases for integration

#ifndef __TESTINTEGRATION_H
#define __TESTINTEGRATION_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "PayStationImpl.h"
#include "AlphaTownFactory.h"
#include "BetaTownFactory.h"

/// Test fixture for ProgressiveRateStrategy
class TestIntegration : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestIntegration);
	CPPUNIT_TEST(testPSLinear2h300c);
	CPPUNIT_TEST(testPSProgressive2h350c);
	CPPUNIT_TEST_SUITE_END();

private:
	PayStation ps;
	
	void add1Dollar()  {
		ps->addPayment(25);  ps->addPayment(25);
		ps->addPayment(25);  ps->addPayment(25); 
	};


public:
	// integrate test PS and Linear strategy
	void testPSLinear2h300c()  {
		ps = new PayStationImpl(new AlphaTownFactory);
		add1Dollar();  add1Dollar();  add1Dollar();
		CPPUNIT_ASSERT(ps->readDisplay() == 120);
		delete ps;
	};

		// integrate test PS and Linear strategy
	void testPSProgressive2h350c()  {
		ps = new PayStationImpl(new BetaTownFactory);
		add1Dollar();  add1Dollar();  add1Dollar();
		ps->addPayment(25);  ps->addPayment(25);
		CPPUNIT_ASSERT(ps->readDisplay() == 120);
		delete ps;
	};

};

#endif
