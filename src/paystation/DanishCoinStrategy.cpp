#include "DanishCoinStrategy.h"
#include "IllegalCoinException.h"

int DanishCoinStrategy::coinInserted(int coin) {
	switch (coin) {
	case 5: return 5;
	case 10: return 10;
	case 25: return 25;
	default: return 0;
	}
}
