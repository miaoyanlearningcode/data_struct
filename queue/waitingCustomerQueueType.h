#include <iostream>
#include "queueType.h"
#include "customerType.h"

using namespace std;

class waitingCustomerQueueType: public queueType<customerType>
{
public:
	waitingCustomerQueueType(int size = 100);

	void updateWaitingQueue();
};

waitingCustomerQueueType::waitingCustomerQueueType(int size)
							:queueType<customerType>(size)
{

}

void waitingCustomerQueueType::updateWaitingQueue()
{
	customerType cust;

	cust.setWaitingTime(-1);
	int wTime = 0;

	addQueue(cust);

	while(wTime != -1)
	{
		cust = front();
		deleteQueue();

		wTime = cust.getWaitingTime();
		if (wTime == -1)
			break;
		cust.incrementWaitingTime();
		addQueue(cust);
	}
}