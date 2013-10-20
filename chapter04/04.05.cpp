#include "../careercup.h"
using namespace std;

bool checkBST(TreeNode *root, int minB, int maxB)
{
    if(!root)
	return true;
    return (root->val > minB && root->val < maxB) && checkBST(root->left, minB, root->val) && checkBST(root->right, root->val, maxB);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode *root = buildBST(a, 0, 9);
    cout << "A BST? " << checkBST(root, INT_MIN, INT_MAX) << endl;

    int b[] = {1, 2, 3, 4, 5, 11, 7, 8, 9, 10};
    TreeNode *root1 = buildBST(b, 0, 9);
    cout << "A BST? " << checkBST(root1, INT_MIN, INT_MAX) << endl;

    return 0;
}
