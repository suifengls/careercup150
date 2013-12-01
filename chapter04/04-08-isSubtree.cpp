#include "../careercup.h"
using namespace std;

bool issameTree(TreeNode *T1, TreeNode *T2)
{
    if(!T1 && !T2)
	return true;
    else if(!T1 || !T2)
	return false;
    return (T1->val == T2->val) && issameTree(T1->left, T2->left) && issameTree(T1->right, T2->right);
}

bool isSubtree(TreeNode *T1, TreeNode *T2)
{
    if(!T1)
	return false;
    if((T1->val == T2->val) && issameTree(T1, T2))
	return true;
    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

int main()
{
    int t1[] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *T1 = buildBST(t1, 0, 6);
    int t2[] = {1, 2, 5};
    TreeNode *T2 = buildBST(t2, 0, 2);
    int t3[] = {1, 2, 3};
    TreeNode *T3 = buildBST(t3, 0, 2);

    cout << "T2 is a subtree of T1? " << isSubtree(T1, T2) << endl;
    cout << "T3 is a subtree of T1? " << isSubtree(T1, T3) << endl;

    return 0;
}
