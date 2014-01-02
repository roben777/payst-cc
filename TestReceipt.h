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
#include "ReceiptImpl.h"

class TestReceipt : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestReceipt);
	CPPUNIT_TEST(testReceiptValue);
	CPPUNIT_TEST_SUITE_END();
	
public:
	void setUp() {
	}

	void tearDown() {
	}

	// test that receipt can hold the value 30 
	void testReceiptValue() {
		Receipt receipt = new ReceiptImpl(30);
		CPPUNIT_ASSERT(receipt->value() == 30);
		delete receipt;
	}
};

#endif
