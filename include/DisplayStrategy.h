/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** DisplayStrategy interface (abstract class)
   Responsibilities:
                        
	 1) Calculate the displayed value shown on screen
*/

#ifndef __DISPLAYSTRATEGY_H
#define __DISPLAYSTRATEGY_H

class DisplayStrategyInterface {
public:
	/// returns the value that should be displayed on the paystation screen
	/// \param [in] timeBought the time purchased in minutes
	/// \return the value to be displayed on the screen
	virtual int calculateOutput(int timeBought) = 0;

	/// virtual destructor, needed so that all classes implementing the interface
	/// have virtual destructors
	virtual ~DisplayStrategyInterface() {};
};

/// the display strategy interface type definition
typedef DisplayStrategyInterface * DisplayStrategy;

#endif
