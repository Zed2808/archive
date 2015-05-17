#ifndef MORESTUFF_H
#define MORESTUFF_H

#include "stuff.h"

class betterthing : public thing {
	private:
		int c;
	public:
		void setC(int x);
		int getC();
};

#endif
