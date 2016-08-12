template <class elemType>
struct binaryTreeNode
{
	elemType info;
	binaryTreeNode<elemType> *llink;
	binaryTreeNode<elemType> *rlink;
};

template <class elemType>
class binaryTreeType
{
public:
	const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);

	bool isEmpty() const;

	void inorderTraversal() const;

	void preorderTraversal() const;

	void postorderTraversal() const;

	int treeHeight() const;

	int treeNodeCount() const;

	int treeLeavesCount() const;

	void destoryTree();

	binaryTreeType(const binaryTreeNode<elemType>& otherTree);

	binaryTreeType();

	~binaryTreeType();

protected:
	binaryTreeNode<elemType> *root;

private:
	void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRot);

	void destory(binaryTreeNode<elemType>* &p);

	void inorder(binaryTreeNode<elemType> *p) const;

	void preorder(binaryTreeNode<elemType> *p) const;

	void postorder(binaryTreeNode<elemType> *p) const;

	int height(binaryTreeNode<elemType> *p) const;

	int max(int x, int y) const;

	int nodeCount(binaryTreeNode<elemType>* p) const;

	int leavesCount(binaryTreeNode<elemType>* p) const;

}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root==NULL);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
	inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
	preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
	postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
	return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
	return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
	return leavesCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
	if (p = NULL) return 0;
	else
		return (1 + max(height(p->llink), height(p->rlink)));
}

template <class elemType>
void binaryTreeType<elemType>::copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRot)
{
	if (otherTreeRot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new binaryTreeNode<elemType>;
		copiedTreeRoot->info = otherTreeRot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRot->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info <<" ";
		inorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p) const
{
	if(p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y) 
		return x;
	else
		return y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType> *p) const
{
	if (p = NULL)
		return 0;
	else
		return (1 + nodeCount(p->llink) + nodeCount(p->rlink));
}

template <class elemType>
itn binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType>* p) const
{
	if (p == NULL)
		return 0;
	else if ((p->llink == NULL) && (p->rlink == NULL))
		return 1;
	else
		return (leavesCount(p->llink) + leavesCount(p->rlink));
}

template <class elemType>
void binaryTreeType<elemType>::destory(binaryTreeNode<elemType>* &p)
{
	if (p != NULL)
	{
		destory(p->llink);
		destory(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void binaryTreeType<elemType>::destoryTree()
{
	destory(root);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType>& otherTree)
{
	if(otherTree.root == NULL)
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destoryTree();
}