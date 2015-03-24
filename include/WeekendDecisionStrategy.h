/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/**Weekend decision interface:
   Responsibilities:
                        
	 1) Decide whether current time is weekend or not
*/

#ifndef __WEEKENDDECISIONSTRATEGY_H
#define __WEEKENDDECISIONSTRATEGY_H


class WeekendDecisionStrategyInterface {
public:
	/// function that determines if current day falls on a weekend
	/// \return true if current day is on a weekend
	virtual bool isWeekend() = 0;

	/// virtual destructor
	virtual ~WeekendDecisionStrategyInterface() {};
};

typedef WeekendDecisionStrategyInterface* WeekendDecisionStrategy;

#endif
