#include "../careercup.h"
using namespace std;

int getHeight(TreeNode *root)
{
    if(!root)
	return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{
    if(!root)
	return true;
    return (abs(getHeight(root->left) - getHeight(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "{1, 2, 3, 4, 5, 6, 7} Balanced? " << isBalanced(root) << endl;

    root->right->right->right = new TreeNode(8);
    root->right->right->right->left = new TreeNode(9);

    cout << "{1, 2, 3, 4, 5, 6, 7, #, #, #, 8, 9, #} Balanced? " << isBalanced(root) << endl;
    
    return 0;
}
	  
