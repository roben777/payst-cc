/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** Implementation of the receipt interface

   Responsibilities:
                        
   1) Hold the amount of time bought
*/

#ifndef __RECEIPTIMPL_H
#define __RECEIPTIMPL_H

#include "Receipt.h"
#include <iostream>
#include <string>

class StandardReceipt : public ReceiptInterface {
private:
	int theValue;

	/// helper function: returns a string consisting of the current
	/// clock time in hh:mm format
	/// \return a string with 5 characters: the clock time in hh:mm
	/// format
	std::string currentTime();
	
public:
	StandardReceipt(int amountOfTime);
	int value();
	void print(std::ostream& str);
};

#endif
