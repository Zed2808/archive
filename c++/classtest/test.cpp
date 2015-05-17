#include "stuff.h"
#include "morestuff.h"
#include <iostream>

using namespace std;

int main() {
	thing x;
	betterthing y;

	x.setA(4);
	x.setB(2);

	y.setA(1);
	y.setB(2);
	y.setC(3);

	cout << "x.getA() returns" << x.getA() << endl;
	cout << "x.getB() returns" << x.getB() << endl;

	cout << "y.getA() returns" << y.getA() << endl;
	cout << "y.getB() returns" << y.getB() << endl;
	cout << "y.getC() returns" << y.getC() << endl;

	return 0;
}
