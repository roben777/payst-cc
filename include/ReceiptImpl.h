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

class ReceiptImpl : public ReceiptInterface {
private:
	int theValue;
public:
	ReceiptImpl(int amountOfTime);
	int value();
};

#endif
