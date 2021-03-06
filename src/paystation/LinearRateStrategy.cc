/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

#include "LinearRateStrategy.h"

int LinearRateStrategy::calculateTime(int amount) {
	return amount / 5 * 2;  // 5 cents are 2 min
}
