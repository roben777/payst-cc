/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/**Implementation for clock bnased weekend decision interface:
   Responsibilities:
                        
	 1) Decide whether current time is weekend or not
*/

#include "ClockBasedDecisionStrategy.h"
#include <ctime>

/// \return true if current day is on a weekend
bool ClockBasedDecisionStrategy::isWeekend() {
	struct tm *timeval;
	time_t tt;
	tt = time( NULL );
	timeval = localtime( &tt );
	// tm_wday: nr of days since Sunday
	return ((timeval->tm_wday == 0) || (timeval->tm_wday == 6));
}

