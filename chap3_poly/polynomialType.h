#include <iostream>

#include "../prob1/arrayList.h"
using namespace std;

class polynomialType: public arrayListType<double>
{
	friend ostream& operator<<(ostream&, const polynomialType&);

	friend istream& operator>>(istream&, polynomialType&);

public:
	polynomialType operator+(const polynomialType&);

	polynomialType operator-(const polynomialType&);

	polynomialType operator*(const polynomialType&);

	double operator() (double x);

	polynomialType(int size = 100);

	int min(int x, int y) const;

	int max(int x, int y) const;

};

polynomialType::polynomialType(int size)
				: arrayListType<double>(size)
{
	length = size;

	for (int i = 0; i < size; i++)
		list[i] = 0;
}

double polynomialType::operator() (double x)
{
	double value = 0.0;

	for (int i = 0; i < length; i++)
	{
		if (list[i] != 0.0)
			value = value + list[i] * pow(x,i);
	}

	return value;
}

polynomialType polynomialType::operator+ (const polynomialType& right)
{
	int size = max(length, right.length);
	
	polynomialType temp(size); //polynomial to store the sum
	
	for (int i = 0; i < min(length, right.length); i++)
		temp.list[i] = list[i] + right.list[i];
	
	if (size == length)
		for (int i = min(length, right.length); i < length; i++)
			temp.list[i] = list[i];
	else
		for (int i = min(length, right.length); i < right.length;i++)
			temp.list[i] = right.list[i];
	
	return temp;
}

polynomialType polynomialType::operator- (const polynomialType& right)
{
	int size = max(length, right.length);

	polynomialType temp(size); //polynomial to store the difference

	for (int i = 0; i < min(length, right.length); i++)
		temp.list[i] = list[i] - right.list[i];

	if (size == length)
		for (int i = min(length, right.length); i < length; i++)
			temp.list[i] = list[i];
	else
		for (int i = min(length, right.length); i < right.length;i++)
			temp.list[i] = -right.list[i];
	
	return temp;
}

int polynomialType::min(int x, int y) const
{
	if (x <= y)
		return x;
	else
		return y;
}

int polynomialType::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

