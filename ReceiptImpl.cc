/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

#include "ReceiptImpl.h"

ReceiptImpl::ReceiptImpl(int amountOfTime) {
	theValue = amountOfTime;
}

int ReceiptImpl::value() {
	return theValue;
}
