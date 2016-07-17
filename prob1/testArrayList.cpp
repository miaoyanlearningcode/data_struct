#include <iostream>

#include <string>
#include "arrayList.h"

using namespace std;

int main()
{
	arrayListType<int> intList(100);
	arrayListType<string> stringList;

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

	cout << "Line 27: Enter the item to be deleted: ";
	cin >> number;
	intList.remove(number);
	cout << "Line 30: after removing " << number << ", the list is: " << endl;
	intList.print();
	cout << endl;

	string str;

	cout << "Line 36: Enter 5 strings: ";

	for (int counter = 0; counter < 5; counter++)
	{
		cin >> str;
		stringList.insertAt(counter, str);
	}

	cout << endl;
	cout << "Line 45: the list you entered is: " << endl;
	stringList.print();
	cout << endl;

	cout << "Line 49: Enter the string to be deleted: ";
	cin >> str;
	stringList.remove(str);
	cout << "Line 52: After removing " << str << ", the list is: "<< endl;
	stringList.print();
	cout << endl;

	return 0;
}