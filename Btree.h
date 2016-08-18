template <class recType, int bTreeOrder>
struct bTreeNode
{
	int recCount;
	recType list[bTreeOrder-1];
	bTreeNode *children[bTreeOrder];
};

template <class recType, int bTreeOrder>
class bTree
{
public:
	bool search(const recType& searchItem);

	void insert(const recType& insertItem);

	void inOrder();

	bTree();

protected:
	bTreeNode<recType, bTreeOrder> *root;
};

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::searchNode(bTreeNode<recType, bTreeOrder> *current, const recType& item, bool &found, int& location)
{
	location = 0;

	while (location < current->recCount && item > current->list[location])
		location++;

	if (location < current->recCount && item == current->list[location])
		found = true;
	else
		found = false;
}

template <class recType, int bTreeOrder>
bool bTree<recType, bTreeOrder>::search(const recType& searchItem)
{
	bool found = false;
	int location;

	bTreeNode<recType, bTreeOrder> *current;

	current = root;

	while (current != NULL && !found)
	{
		searchNode(current, item, found,location);

		if (!found)
			current = children[location];
	}
	return found;
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::inOrder()
{
	recInorder(root);
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::recInorder(bTreeNode<recType, bTreeOrder> *current)
{
	if (current != NULL)
	{
		recInorder(current->children[0]);

		for (int i = 0; i < current->recCount; i++)
		{
			cout << current->list[i] << " ";
			recInorder(current->children[i + 1]);
		}
	}
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insert (const recType& insertItem)
{
	bool isTaller = false;
	recType median;

	bTreeNode<recType, bTreeOrder> *rightChild;
	insertBTree(root, insertItem, median, rightChild, isTaller);

	if (isTaller)
	{
		bTreeNode<recType, bTreeOrder> *tempRoot;
		tempRoot = new bTreeNode<recType, bTreeOrder>;
		tempRoot->recCount = 1;
		tempRoot->list[0] = median;
		tempRoot->children[0] = root;
		tempRoot->children[1] = rightChild;

		root = tempRoot;
	}
}
