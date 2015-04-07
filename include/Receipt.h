/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** The receipt returned from a pay station.
   Responsibilities:
                        
   1) Know the minutes parking time the receipt represents
*/

#ifndef __RECEIPT_H
#define __RECEIPT_H

#include <iostream>

class ReceiptInterface {
public:
  /**
   * Return the number of minutes this receipt is valid for.
   * @return number of minutes parking time
  */
  virtual int value() = 0;

	/**
		 Print a receipt to an output stream
		 \param [in] str the stream to print the receipt to
	*/
	virtual void print(std::ostream& str) = 0;
	
	/**
	 * Virtual destructor: will be called by the concrete Receipt
	 * class destructor.
	 */
	virtual ~ReceiptInterface() {};
};

/// Type definition wrapper for the interface (in C++, it is a
/// pointer)
typedef ReceiptInterface* Receipt;

#endif
