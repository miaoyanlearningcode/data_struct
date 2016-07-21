#include <iostream>

#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	deque<int> intDeq;
	ostream_iterator<int> screen(cout, " ");

	intDeq.push_back(13);
	intDeq.push_back(75);
	intDeq.push_back(28);
	intDeq.push_back(35);

	cout << "Line 19: intDeq: ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	intDeq.push_front(0);
	intDeq.push_back(100);

	cout << "Line 26: After adding two more elements, one at front and one at the back, intDeq: ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;
	
	intDeq.pop_front();
	intDeq.pop_front();

	cout << "Line 33: After removing first two elements, intDeq: ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	intDeq.pop_back();
	intDeq.pop_back();

	cout << "Line 39: After removing last two elements, intDeq: ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	deque<int>::iterator deqIt;

	deqIt = intDeq.begin();
	++deqIt;
	intDeq.insert(deqIt, 444);

	cout << "Line 50: After inserting 444, intDeq: ";
	copy(intDeq.begin(), intDeq.end(), screen);
	cout << endl;

	return 0;
}