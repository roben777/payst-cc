/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

#include "PayStationImpl.h"

void PayStationImpl::addPayment( int coinValue )
	throw (IllegalCoinException){
}
  
int PayStationImpl::readDisplay() {
	return 0;
}
  
Receipt PayStationImpl::buy() {
	return NULL;
}

void PayStationImpl::cancel() {
}

PayStationImpl::~PayStationImpl() {
}
