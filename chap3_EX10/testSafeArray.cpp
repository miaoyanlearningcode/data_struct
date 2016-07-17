#include <iostream>
#include "safeArray.h"

using namespace std;

int main()
{
	safeArray list(2,13);
	safeArray yourList(-5,9);
	
	cin >> list;
	cout << list << endl;

	cout << list[4] << endl;


	cin >> yourList;
	cout << yourList << endl;
	cout << yourList[-3] << endl;
	return 0;
}