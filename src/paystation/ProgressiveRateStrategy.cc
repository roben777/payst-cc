/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

#include "ProgressiveRateStrategy.h"

int ProgressiveRateStrategy::calculateTime(int amount) {
	if (amount > 350)  {
		return 120 + (amount - 350) / 5;
	}
	else if (amount > 150)  {
		return 60 + (amount - 150) / 10 * 3; // 5 cents are 1.5 min
	}
	else  {		
		return amount / 5 * 2;  // 5 cents are 2 min for first hour
	}
}
