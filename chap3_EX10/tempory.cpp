#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int intArray[5] = {2,4,6,8,10};

	for(int i = 0;i < 5; i++)
		cout << intArray + i << " ";

	cout << endl;

	vector<int> intList(intArray, intArray + 5);
	for(int i = 0; i < 5; i++)
		cout << intList[i] << " ";

	cout << endl;

	intList.push_back(34);
	cout << intList.back() << endl;

	cout << intList.size() << endl;
	//intList.insert(3,45);
	//intList.resize(9,3);
	cout << intList.size() << endl;

	vector<int>::iterator intVecIter;
	for (intVecIter = intList.begin(); intVecIter != intList.end(); intVecIter++)
		cout << *intVecIter << " ";

	cout << endl;

	cout << *(intList.rend() + 2) << endl;

	return 0;
}