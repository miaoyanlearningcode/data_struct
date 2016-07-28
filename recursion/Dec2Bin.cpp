#include <iostream>

using namespace std;

void Dec2Bin(int dec);

int main()
{
	int Dec;
	
	cin >> Dec;

	Dec2Bin(Dec);
	cout << endl;
	
	return 0;

}

void Dec2Bin(int dec)
{
	if (dec > 0)
	{
		Dec2Bin(dec/2);
		cout << dec%2;
	}
}