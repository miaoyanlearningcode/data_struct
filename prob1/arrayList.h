#include <iostream> 
using namespace std;

template <class elemType>
class arrayListType
{
public:
	const arrayListType<elemType>& operator=
							(const arrayListType<elemType>&);
    // donot understand & here
	bool isEmpty() const;

	bool isFull() const;

	int listSize() const;

	int maxListSize() const;

	void print() const;

	bool isItemAtEqual(int location, const elemType& item) const;
		//Function to determine whether the item is the same as
		//the item in the list at the position specified by
	void insertAt(int location, const elemType& insertItem);

	void insertEnd(const elemType& insertItem);

	void removeAt(int location);

	void retrieveAt(int location, elemType& retItem) const;

	void replaceAt(int location, const elemType& repItem);

	void clearList();

	int seqSearch(const elemType& item) const;

	void insert(const elemType& insertItem);
	// insert item in the end of list and check if inserted is 
	// already in the list

	void remove(const elemType& removeItem);
	//function to remove the specific item

	arrayListType(int size = 100);
	//constructor maxSize = 100 here

	arrayListType(const arrayListType<elemType>& otherList);
	// copy constructor

	~arrayListType();
	//destructor

protected:
	elemType *list;
	int length;
	int maxSize;
};

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
						(const arrayListType<elemType>& otherList)
{
	if (this != &otherList)
	{
		delete [] list;
		maxSize = otherList.maxSize;
		length = otherList.length;

		list = new elemType[maxSize];
		assert(list != NULL);

		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}
	return *this;
}

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
	return (length == 0);
}

template<class elemType>
bool arrayListType<elemType>::isFull() const
{
	return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
	return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
	return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
	for(int i = 0; i < length; i++)
		cout << list[i] << " ";

	cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual
							(int location, const elemType& item) const
{
	return (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
	if(location < 0 || location >= maxSize)
		cerr << "The position of the item to be inserted is out of range" << endl;
	else
		if(length >= maxSize)
			cerr << "Cannot insert in a full list" << endl;
		else
		{
			for(int i = length; i > location; i--)
				list[i] = list[i - 1];

			list[location] = insertItem;

			length++;
		}
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
	if(length >= maxSize)
		cerr << "Cannot insert in a full list" << endl;
	else
	{
		list[length] = insertItem;
		length++;
	}
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cerr << "The position of the item to be inserted is out of range" << endl;
	else
	{
		for(int i = location; i < length - 1; i++)
			list[i] = list[i+1];

		length--;
	}
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const
{
	if(location < 0 || location >= length)
		cerr << "The position of the item to be inserted is out of range" << endl;
	else
		retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
	if (location < 0 || location >= length)		
		cerr << "The position of the item to be inserted is out of range" << endl;
	else
		list[location] = repItem;
}

template <class elemType>
void arrayListType<elemType>::clearList()
{
	length = 0;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;

	for(loc = 0; loc < length; loc++)
	{
		if (list[loc] == item)
		{
			found = true;
			break;
		}
	}
	if(found)
		return loc;
	else 
		return -1;
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
	int loc;

	if (length == 0)
		list[length++] = insertItem;
	else if (length == maxSize)
		cerr << "Cannot insert in a full list. " << endl;
	else
	{
		loc = seqSearch(insertItem);

		if (loc == -1)
			list[length++] = insertItem;
		else
			cerr << "the item to be inserted is already in the list. No duplicated are allowed" << endl;
	}
}

template <class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
	int loc;

	if (length == 0)
		cerr << "Cannot delete from an empty list. " << endl;
	else
	{
		loc = seqSearch(removeItem);

		if(loc != -1)
			removeAt(loc);
		else
			cout << "the item to be deleted is not in the list. " << endl;
	}
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive. Creating an array of size 100. " << endl;
		maxSize = 100;
	}
	else
		maxSize = 100;

	length = 0;

	list = new elemType[maxSize];
	assert(list != NULL);
}//constructor

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new elemType[maxSize];
	assert(list != NULL);

	for(int j = 0; j < length; j++)
		list[j] = otherList.list[j];
}//copy constructor;

template<class elemType>
arrayListType<elemType>::~arrayListType()
{
	delete [] list;
}

