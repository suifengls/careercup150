#include "../careercup.h"
using namespace std;

bool isLeft(TreeNode *root, TreeNode *p)
{
    if(!root)
	return false;
    if(root == p)
	return true;
    return isLeft(root->left, p) || isLeft(root->right, p);
}

TreeNode *findCommon(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(!root)
	return NULL;
    if(p == root || q == root)
	return root;
    bool isleftp = false;
    bool isleftq = false;
    if(root->left)
    {
	isleftp = isLeft(root->left, p);
	isleftq = isLeft(root->left, q);
    }
    if(isleftp != isleftq)
	return root;
    else if(isleftp)
	return findCommon(root->left, p, q);
    else
	return findCommon(root->right, p, q);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = buildBST(a, 0, 6);
    TreeNode *p = root->left->left;
    TreeNode *q = root->right;
    cout << p->val << " and " << q->val << " first common ancestor " << findCommon(root, p, q)->val << endl;

    return 0;
}
