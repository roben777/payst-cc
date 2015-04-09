#ifndef __VALIDCOINSTRATEGY_H
#define __VALIDCOINSTRATEGY_H

class ValidCoinStrategy {
public:
	virtual int coinInserted(int) = 0;
	virtual ~ValidCoinStrategy() {};

};

typedef ValidCoinStrategy *ValidCoin;

#endif