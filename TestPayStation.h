/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// Testcases for the Pay Station System

#ifndef __TESTPAYSTATION_H
#define __TESTPAYSTATION_H

#include <cppunit/TestCase.h>
#include "PayStationImpl.h"

class TestPayStation : public CppUnit::TestCase {
public:
TestPayStation(std::string name) : CppUnit::TestCase(name) {};

	/// the test function. Should display 2 minutes for 5 cents
	void test5CentsIs2Min() {
		PayStation ps = new PayStationImpl;
		ps->addPayment(5);
		CPPUNIT_ASSERT(2 == ps->readDisplay());
		delete ps;
	};
};

#endif
