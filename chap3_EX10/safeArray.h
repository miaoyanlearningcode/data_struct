#include <iostream>

using namespace std;

class safeArray
{
	friend ostream& operator<<(ostream&, const safeArray&);

	friend istream& operator>>(istream&, safeArray&);

public:
	int operator[](const int&) const;
	safeArray(int start = 0, int last = 100);
	~safeArray();

protected:
	int begin;
	int finish;
	int *list;
};


ostream& operator<<(ostream& os, const safeArray& p)
{
	for(int i = 0; i < p.finish - p.begin; i++){
		os << p.list[i] << " ";
	}
	//os << endl;
	return os;
}

istream& operator>>(istream& is, safeArray& p)
{
	cout << "Enter value of array:" <<endl;
	for (int i = 0; i < p.finish - p.begin;i++){
		cout << "Enter " << i + p.begin << "th value : ";
		is >> p.list[i];
	}
	return is;
}




safeArray::safeArray(int start, int last)
{
	if(last > start){
		begin = start;
		finish = last;
		list = new int[last - start];
	} else{
		cout << "Index of beginning must larger than index of ending"<< endl;
		start = 0;
		last = 100;
	}
}

int safeArray::operator[](const int &i) const
{
	int value;
	if (i < begin || i > finish)
		cerr << "Index out of bound"<< endl;
	else
		value = list[i - begin];

	return value;
}

safeArray::~safeArray()
{
	delete [] list;
}