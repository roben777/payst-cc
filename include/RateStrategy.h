/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** RateStrategy interface (abstract class)
   Responsibilities:
                        
	 1) Calculate parking time
*/

#ifndef __RATESTRATEGY_H
#define __RATESTRATEGY_H

/// RateStrategy interface (abstract class)
class RateStrategyInterface {
public:

	/// abstract function: calculates the parking time based on inserted payment
	/// \param [in] amount total inserted payment, in cents
	/// \return the number of minutes of parking for the given amount 
	virtual int calculateTime(int amount) = 0;

	/// virtual destructor
	virtual ~RateStrategyInterface() {};
};

/// RateStrategy type for interface (a pointer to the abstract class)
typedef RateStrategyInterface* RateStrategy;

#endif
