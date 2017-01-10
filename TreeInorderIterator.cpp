/* 	
	A binary tree node has data, pointer to left child
	and a pointer to right child 
*/

struct TreeNode
{
	int Data;
	struct TreeNode* pLeft;
	struct TreeNode* pRight;
};

/* 
	Helper function that allocates a new node with the
	given data and NULL left and right pointers. 
*/
TreeNode* AddNodeTree(int iData)
{
	TreeNode* pNode = new TreeNode();
	pNode->Data = iData;
	pNode->pLeft = NULL;
	pNode->pRight = NULL;

	return(pNode);
}

/* 
	Given a binary tree, print its nodes according to the
	"bottom-up" postorder traversal. 
*/
void printPostorder(struct TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	// first recur on left subtree
	printPostorder(pNode->pLeft);

	// then recur on right subtree
	printPostorder(pNode->pRight);

	// now deal with the node
	printf("%d ", pNode->Data);
}

/* Given a binary tree, print its nodes in inorder */
void printInorder(struct TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	// first recur on left child 
	printInorder(pNode->pLeft);

	// then print the data of node 
	printf("data:%d k:%d, ", pNode->Data);

	// now recur on right child 
	printInorder(pNode->pRight);
}

/* Given a binary tree, print its nodes in preorder */
void printPreorder(struct TreeNode* pNode)
{
	if (pNode == NULL)
		return;

	// first print data of node 
	printf("%d ", pNode->Data);

	// then recur on left sutree 
	printPreorder(pNode->pLeft);

	// now recur on right subtree 
	printPreorder(pNode->pRight);
}

/*
 Tree iterator impelmenting Inorder traversal
*/

class TreeInOrderIter
{
public:
	TreeInOrderIter(TreeNode* pRoot)
	{
		TraverseLeft(pRoot);
	}
	
	TreeNode* GetNext();
	bool HasNext();

protected:
	void TraverseLeft(TreeNode* pTree);
	std::stack<TreeNode*> s;

};

void TreeInOrderIter::TraverseLeft(TreeNode* pTree)
{
	if (pTree == nullptr)
	{
		return;
	}

	s.push(pTree);
	TraverseLeft(pTree->pLeft);
}

TreeNode* TreeInOrderIter::GetNext()
{
	if (!HasNext())
	{
		cout << "No more nodes!" << endl;
		return nullptr;
	}
	
	TreeNode * next_node = s.top();
	s.pop();

	if (next_node->left != nullptr)
	{
		TraverseLeft(next_node->right);
		return next_node;
	}
	//Else: the node is root of a subtree.

	return next_node;
}

bool TreeInOrderIter::HasNext()
{
	return s.size() > 0;

}

/* Driver program to test above functions*/
int TreeTraversals()
{
	struct TreeNode *root = newNodeTree(4);
	root->left = newNodeTree(2);
	root->right = newNodeTree(6);
	root->left->left = newNodeTree(1);
	root->left->right = newNodeTree(3);
	root->right->left = newNodeTree(5);
	root->right->right = newNodeTree(7);

	printf("\nPreorder traversal of binary tree is \n");
	printPreorder(root);

	printf("\nInorder traversal of binary tree is \n");
	printInorder(root);

	printf("\nPostorder traversal of binary tree is \n");
	printPostorder(root);

	printf("\nInorder-iterator traversal of binary tree is \n");
	TreeInOrderIter Iterator(root);
	while (Iterator.HasNext())
	{
		cout << Iterator.GetNext()->data << ",";
	}
	getchar();
	return 0;
}

void main
{
	TreeTraversals();
	int k;
	cin << k;
}
