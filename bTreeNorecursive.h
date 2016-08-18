template <class elemType>
void binaryTreeType<elemType>::nonRecursiveInTraversal() const
{
	stackType<binaryTreeNode<elemType>*> stack;
	binaryTreeNode<elemType>* current;
	current = root;

	while ((current != NULL) || (!stack.isEmptyStack()))
	{
		if (current != NULL)
		{
			stack.push(current);
			current = current->llink;
		}
		else
		{
			current = stack.top();
			stack.pop();
			cout << current->info << " ";
			current = current->rlink;
		}
	}
	cout << endl;
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursivePreTraversal() const
{
	stackType<binaryTreeNode<elemType>*> stack;
	binaryTreeNode<elemType>* current;
	current = root;

	while ((current != NULL) || (!stack.isEmptyStack()))
	{
		if (current != NULL)
		{
			cout << current->info << " ";
			current = current->llink;
			stack.push(current->rlink);
		}
		else
		{
			current = stack.top();
			stack.pop();
		}
	}
	cout << endl;
}

template<class elemType>
void binaryTreeType<elemType>::nonRecursivePosTraversal() const
{
	
}