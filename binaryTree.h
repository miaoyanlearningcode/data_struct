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

	int nodeCOunt(binaryTreeNode<elemType>* p) const;

	int leavesCount(binaryTreeNode<elemType>* p) const;

}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root==NULL);
}


















template <class elemType>
int height(binaryTreeNode<elemType> *p) const
{
	if (p = NULL) return 0;
	else
		return (1 + max(height(p->llink), height(p->rlink)));
}

template <class elemType>
void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRot)
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
void inorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info <<" ";
		inorder(p->rlink);
	}
}

template <class elemType>
void preorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class elemType>
void postorder(binaryTreeNode<elemType> *p) const
{
	if(p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}