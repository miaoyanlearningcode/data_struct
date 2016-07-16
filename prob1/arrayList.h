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