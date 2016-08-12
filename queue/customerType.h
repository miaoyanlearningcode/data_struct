#include <iostream>

using namespace std;

class customerType
{
public:
	customerType(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0);

	void setCustomerInfo(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0);

	int getWaitingTime() const;

	void setWaitingTime(int time);

	void incrementWaitingTime();

	int getArrivalTime() const;

	int getTransactionTime() const;

	int getCustomerNumber() const;

private:
	int customerNumber;

	int arrivalTime;

	int waitingTime;

	int transactionTime;

};


void customerType::setCustomerInfo(int cN, int arrvTime, int wTime, int tTime)
{
	customerNumber = cN;
	arrivalTime = arrvTime;
	waitingTime = wTime;
	transactionTime = tTime;
}

customerType::customerType(int cN, int arrvTime, int wTime, int tTime)
{
	setCustomerInfo(cN, arrvTime, wTime, tTime);
}

int customerType::getWaitingTime() const
{
	return waitingTime;
}

void customerType::incrementWaitingTime()
{
	waitingTime++;
}

void customerType::setWaitingTime(int time)
{
	waitingTime = time;
}

int customerType::getArrivalTime() const
{
	return arrivalTime;
}

int customerType::getTransactionTime() const
{
	return transactionTime;
}

int customerType::getCustomerNumber() const
{
	return customerNumber;
}