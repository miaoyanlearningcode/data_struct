#include <iostream>

#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int intArray[] = {5,6,8,3,40,36,98,29,75};
	vector<int> vecList(9);

	copy(intArray, intArray + 9, vecList.begin());

	ostream_iterator<int> screen(cout," ");

	copy(vecList.begin(), vecList.end(), screen);
	cout << endl;

	return 0;
}