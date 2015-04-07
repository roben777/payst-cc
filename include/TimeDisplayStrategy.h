/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** class implementing the DisplayStrategy interface that prints end
   parking time
   Responsibilities:
                        
	 1) Calculate the displayed value shown on screen
*/

#ifndef __TIMEDISPLAYSTRATEGY_H
#define __TIMEDISPLAYSTRATEGY_H

#include "DisplayStrategy.h"

class TimeDisplayStrategy : public DisplayStrategyInterface {
public:
	int calculateOutput(int timeBought);

	~TimeDisplayStrategy() {};
};


#endif
