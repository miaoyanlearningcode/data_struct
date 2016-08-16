template <class elemType>
struct AVLNode
{
	elemType info;
	int bfactor;
	AVLNode<elemType> *llink;
	AVLNode<elemType> *rlink;
};

template <class elemType>
void rotateToLeft(AVLNode<elemType>* &root)
{
	AVLNode<elemType> *p;

	if (root == NULL)
		cerr << "Error in the tree" << endl;
	else if (root->llink == NULL)
		cerr << "Error in the tree: No right subtree to rotate." << endl;
	else
	{
		p = root->rlink;
		root->rlink = p->llink;
		p->llink = root;
		root = p;
	}
}

template <class elemType>
void rotateToRight(AVLNode<elemType>* &root)
{
	AVLNode<elemType> *p;

	if (root == NULL)
		cerr << "Error in the tree. " << endl;
	else if (root->llink == NULL)
		cerr << "Error in the tree: No left subtree to rotate." << endl;
	else
	{
		p = root->llink;
		root->llink = p->rlink;

		p->rlink = root;
		root = p;
	}
}

template <class elemType>
void balanceFromLeft(AVLNode<elemType>* &root)
{
	AVLNode<elemType> *p;
	AVLNode<elemType> *w;

	p = root->llink;

	switch (p->bfactor)
	{
		case -1:
			root->bfactor = 0;
			p->bfactor = 0;
			rotateToRight(root);
			break;
		case 0:
			cerr << "Error: Cannot balance from the left." << endl;
		case 1:
			w = p->rlink;
			switch (w->bfactor)
			{
				case -1:
					root->bfactor = 1;
					p->bfactor = 0;
					break;
				case 0:
					root->bfactor = 0;
					p->bfactor = 0;
					break;
				case 1:
					root->bfactor = 0;
					p->bfactor = -1;
			}

			w->bfactor = 0;
			rotateToLeft(p);
			root->llink = p;
			rotateToRight(root);
		}
	}
}

template <class elemType>
void balanceFromRight (AVLNode<elemType>* &root)
{
	AVLNode<elemType> *p;
	AVLNode<elemType> *w;

	p = root->rlink;

	switch (p->bfactor)
	{
		case -1:
			w = p->llink;
			switch (w->bfactor)
			{
				case -1:
					root->bfactor = 0;
					p->bfactor = 1;
					break;
				case 0:
					root->bfactor = 0;
					p->bfactor = 0;
					break;
				case 1:
					root->bfactor = -1;
					p->bfactor = 0;
			}
			w->bfactor = 0;
			rotateToRight(p);
			root->rlink = p;
			rotateToLeft(root);
			break;
		case 0:
			cerr << "Error: Cannot balance from the left." << endl;

		case 1:
			root->bfactor = 0;
			p->bfactor = 0;
			rotateToLeft(root);
	}
}

template <class elemType>
void insertIntoAVL (AVLNode<elemType>* &root, AVLNode<elemType> *newNode, bool &isTaller)
{
	if (root == NULL)
	{
		root = newNode;
		isTaller = true;
	}
	else if (root->info == newNode->info)
		cerr << "No duplicates are allowed." << endl;
	else if (root->info > newNode->info)
	{
		insertIntoAVL(root->llink, newNode, isTaller);

		if (isTaller)
			switch (root->bfactor)
			{
			case -1:
				balanceFromLeft(root);
				isTaller = false;
				break;
			case 0:
				root->bfactor = -1;
				isTaller = true;
				break;
			case 1:
				root->bfactor = 0;
				isTaller = false;
			}
	}
	else 
	{
		insertIntoAVL(root->rlink, newNode, isTaller);
		if (isTaller)
			switch (root-bfactor)
			{
			case -1:
				root->bfactor = 0;
				isTaller = false;
				break;
			case 0:
				root->bfactor = 1;
				isTaller = true;
				break;
			case 1:
				balanceFromRight(root);
				isTaller = false;
			}
	}
}

template <class elemType>
void insert (const elemType &newItem)
{
	bool isTaller = false;
	AVLNode<elemType> *newNode;

	newNode = new AVLNode<elemType>;
	newNode->info = newItem;
	newNode->bfactor = 0;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	insertIntoAVL(root, newNode, isTaller);
}