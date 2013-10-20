#include "../careercup.h"
using namespace std;

TreeNode *buildBST0(int a[], int s, int e)
{
    if(s > e)
	return NULL;
    int mid = (s + e)/2;
    TreeNode *root = new TreeNode(a[mid]);
    root->left = buildBST0(a, s, mid-1);
    root->right = buildBST0(a, mid+1, e);
    return root;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    TreeNode *root = buildBST0(a, 0, 5);
    printTree(root);
}
