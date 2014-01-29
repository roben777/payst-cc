/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** PayStation interface (abstract class)
   Responsibilities:
                        
   1) Accept payment;
   2) Calculate parking time based on payment;
   3) Know earning, parking time bought;
   4) Issue receipts;
   5) Handle buy and cancel events.
*/
 
#ifndef __PAYSTATION_H
#define __PAYSTATION_H

#include "IllegalCoinException.h"
#include "Receipt.h"

class PayStationInterface {
public:
/**
   * Insert coin into the pay station and adjust state accordingly.
   * @param coinValue is an integer value representing the coin in
   * cent. That is, a quarter is coinValue=25, etc.
   * @throws IllegalCoinException in case coinValue is not 
   * a valid coin value
   */
  virtual void addPayment( int coinValue ) throw (IllegalCoinException) = 0;
  
  /**
   * Read the machine's display. The display shows a numerical
   * description of the amount of parking time accumulated so far
   * based on inserted payment.  
   * @return the number to display on the pay station display
   */
  virtual int readDisplay() = 0;

  /**
   * Buy parking time. Terminate the ongoing transaction and
   * return a parking receipt. A non-null object is always returned.
   * @return a valid parking receipt object.
   */ 
  virtual Receipt buy() = 0;

  /**
   * Cancel the present transaction. Resets the machine for a new
   * transaction.
   */  
  virtual void cancel() = 0;

	/**
	 * Virtual destructor: will be called by the concrete PayStation
	 * class destructor.
	 */
	virtual ~PayStationInterface() {};
};

/// Type definition wrapper for the interface (in C++, it is a
/// pointer)
typedef PayStationInterface * PayStation;

#endif
