#include <iostream>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left, *right, *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {};
}TreeNode;

TreeNode *buildBST(int a[], int s, int e, TreeNode *parent)
{
    if(s > e)
	return NULL;
    int mid = (s + e)/2;
    TreeNode *root = new TreeNode(a[mid]);
    root->parent = parent;
    root->left = buildBST(a, s, mid-1, root);
    root->right = buildBST(a, mid+1, e, root);
    return root;
}

TreeNode *findNext(TreeNode *root)
{
    if(!root)
	return NULL;
    if(root->right)
    {
	TreeNode *node = root->right;
	while(node->left)
	    node = node->left;
	return node;
    }
    else
    {
	TreeNode *node = root->parent;
	while(node && node->left != root)
	{
	    root = node;
	    node = node->parent;
	}
	return node;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = buildBST(a, 0, 6, NULL);
    TreeNode *succ = findNext(root->left->right);
    cout << root->left->right->val << " next -> " << succ->val << endl;

    TreeNode *succ1 = findNext(root->right);
    cout << root->right->val << " next -> " << succ1->val << endl;
    return 0;
}
