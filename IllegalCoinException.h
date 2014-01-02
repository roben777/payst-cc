/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

#ifndef __ILLEGALCOINEXCEPTION_H
#define __ILLEGALCOINEXCEPTION_H

#include <exception>
#include <string>

/** Exception representing illegal coin entry.
 */
class IllegalCoinException : public std::exception {
public:
	/**
	 * @param e is a description of the exception
	 */
	IllegalCoinException( std::string e ) {};
};

#endif
