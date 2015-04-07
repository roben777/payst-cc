/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** ValueDisplayStrategy class implementing the DisplayStrategy interface
   Responsibilities:
                        
	 1) Calculate the displayed value shown on screen as minutes purchased
*/

#ifndef __VALUEDISPLAYSTRATEGY_H
#define __VALUEDISPLAYSTRATEGY_H

#include "DisplayStrategy.h"

class ValueDisplayStrategy : public DisplayStrategyInterface {
public:
	int calculateOutput(int timeBought);

	~ValueDisplayStrategy() {};
};

#endif
