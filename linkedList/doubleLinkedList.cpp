#include <iostream>

using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType *next;
	nodeType *back;
};
/* Ordered Double Linked List*/
template <class Type>
class doubleLinkedList
{
public:
	const doubleLinkedList<Type>& operator=(const doubleLinkedList<Type> &);

	void initializeList();

	bool isEmptyList();

	void destroy();

	void print() const;

	void reversePrint() const;

	int length() const;

	Type front() const;

	Type back() const;

	bool search(const Type& searchItem);

	void insert(const Type& insertItem);

	void deleteNode(const Type& deleteItem);

	doubleLinkedList();

	doubleLinkedList(const doubleLinkedList<Type>& otherList);

	~doubleLinkedList();

protected:
	int count;
	nodeType<Type> *first;
	nodeType<Type> *last;

private:
	void copyList(cont doubleLinkedList<Type>& otherList);

};

template <class Type>
doubleLinkedList<Type>::doubleLinkedList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template <class Type>
bool doubleLinkedList<Type>::isEmptyList() const
{
	return (first == NULL);
}

template <class Type>
void doubleLinkedList<Type>::destroy()
{
	nodeType<Type> *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}

	last = NULL;
	count = 0;
}

template <class Type>
void doubleLinkedList<Type>::initializeList()
{
	destroy();
}

template <class Type>
void doubleLinkedList<Type>::print() const
{
	nodeType<Type> *current;

	current = first;

	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->next;
	}
}

template <class Type>
void doubleLinkedList<Type>::reversePrint() const
{
	nodeType<Type> *current;

	current = last;

	while (current != NULL)
	{
		cout <<current->info << " ";
		current = current->back;
	}
}

template <class Type>
void doubleLinkedList<Type>::search(const Type& searchItem)
{
	bool found = false;
	nodeType<Type> *current;

	current = first;

	while (current != NULL && !found)
	{
		if (current->info >= searchItem)
			found = true;
		else
			current = current->next;
	}

	if (found)
		found = (current->info == searchItem);

	return found;
}

template <class Type>
Type doubleLinkedList<Type>::front() const
{
	assert(first != NULL);

	return first->info;
}

template <class Type>
Type doubleLinkedList<Type>::back() const
{
	assert(last != NULL);

	return last->info;
}

template <class Type>
void doubleLinkedList<Type>::insert(const Type& insertItem)
{
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;
	nodeType<Type> *newNode;
	bool found;

	newNode = new nodeType<Type>;

	newNode->info = insertItem;
	newNode->next = NULL;
	newNode->back = NULL;

	if (first == NULL)
	{
		first = newNode;
		las = newNode;
		count++;
	}
	else
	{
		found = false;
		current = first;

		while (current != NULL && !found)
		{
			if(current->info >= insertItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		}

		if(current == first)
		{
			first->back = newNode;
			newNode->next = first;
			first = newNode;
			count++;
		}
		else
		{
			if (current != NULL)
			{
				current->back = newNode;
				newNode->next = current;
				newNode->back = trailCurrent;
				trailCurrent->next = newNode;
				count++;
			}
			else
			{
				trailCurrent->next = newNode;
				newNode->back = trailCurrent;
				last = newNode;
				count++;
			}
		}
	}
}

template <class Type>
void doubleLinkedList<Type>::deleteNode(const Type& deleteItem)
{

	newNode<Type> *current;
	newNode<Type> *trailCurrent;
	bool found;

	if(first == NULL)
	{
		cout << "Cannot delete from an empty list." << endl;
	}
	else if (first->info == deleteItem)
	{
		current = first;
		first = first->next;

		if (first != NULL)
			first->back = NULL;
		else
			last = NULL;

		count--;
		delete current;
	}
	else
	{
		current = first;
		found = false;

		while (current != NULL && !found)
		{
			if (current->info >= deleteItem)
				found = true;
			else
				{
					trailCurrent = current;
					current = current->next;
				}
		}

		if (current == NULL)
			cout << "The item to be delete is not in the list." << endl;
		else if (current->info == deleteItem)
		{
			trailCurrent = current->back;
			trailCurrent->next = current->next;

			if (current->next != NULL)
				current->next->back = trailCurrent;

			if (current == last)
				last = trailCurrent;

			count--;
			delete current;
		}
		else
			cout << "The item to be deleted is not in the list." << endl;
	}
}