#include <iostream>

#include <string>
#include "arrayList.h"

using namespace std;

int main()
{
	arrayListType<int> intList(100);
	//arrayListType<string> stringList;

	int number;

	cout << "List 15: Enter 5 interges:";
	for (int counter = 0; counter < 5; counter++)
	{
		cin >> number;
		intList.insertAt(counter, number);
	}
	cout << endl;

	cout << "List 23: The list you entered is: ";
	intList.print();
	cout << endl;


	return 0;
}