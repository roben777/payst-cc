/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** Implementation of the pay station.

   Responsibilities:
                        
   1) Accept payment;
   2) Calculate parking time based on payment;
   3) Know earning, parking time bought;
   4) Issue receipts;
   5) Handle buy and cancel events.
*/

#ifndef __PAYSTATIONIMPL_H
#define __PAYSTATIONIMPL_H

#include "PayStation.h"

class PayStationImpl : public PayStationInterface {
private:
	int insertedSoFar;
public:
	// initialize members in default constructor
	PayStationImpl() { insertedSoFar = 0; };
	
  void addPayment( int coinValue )
		throw (IllegalCoinException);
  
  int readDisplay();
  
  Receipt buy();

  void cancel();

	virtual ~PayStationImpl();
};

#endif
