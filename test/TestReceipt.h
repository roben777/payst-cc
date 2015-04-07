/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// Testcases for the Receipt interface implementation

#ifndef __TESTRECEIPT_H
#define __TESTRECEIPT_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "StandardReceipt.h"

class TestReceipt : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestReceipt);
	CPPUNIT_TEST(testReceiptValue);
	CPPUNIT_TEST(testPrint);
	CPPUNIT_TEST_SUITE_END();

private:
	Receipt receipt;
	
public:
	void setUp() {
		receipt = new StandardReceipt(30);
	}

	void tearDown() {
		delete receipt;
	}

	// test that receipt can hold the value 30 
	void testReceiptValue() {
		CPPUNIT_ASSERT(receipt->value() == 30);
	}

	// test the print function
	void testPrint() {
		std::ostringstream sstr;
		receipt->print(sstr);
		std::string s = sstr.str();  // get the output as string
		std::size_t line1 = s.find('\n');
		std::size_t line2 = s.find('\n',line1+1);
		std::size_t lineCollon = s.find(':', line2+1);
		CPPUNIT_ASSERT(s.substr(0, line1) == "PARKING RECEIPT");
		CPPUNIT_ASSERT(s.substr(line1+1, line2-line1-1) == "Value: 30 min.");
		CPPUNIT_ASSERT(s.substr(line2+1, lineCollon-line2-1) == "Car parked at");
		CPPUNIT_ASSERT(s[lineCollon+4] == ':');
	}
};

#endif
