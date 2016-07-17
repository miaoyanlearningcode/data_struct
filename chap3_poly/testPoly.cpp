#include <iostream>

#include "polynomialType.h"

using namespace std;

int main()
{
	polynomialType p(8);
	polynomialType q(4);
	polynomialType t;
	
	cin >> p;
	cout << endl << "Line 14: p(x): " << p << endl;

	cout << "Line 16: p(5): " << p(5) << endl << endl;

	cin >> q;
	cout << endl << "Line 19: q(x): " << q << endl << endl;

	t = p + q;

	cout << "Line 23: p(x) + q(x): " << t << endl;

	cout << "Line 25: p(x) - q(x): " << p - q << endl;
	
	return 0;
}