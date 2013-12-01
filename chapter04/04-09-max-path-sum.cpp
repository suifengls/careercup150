#include "../careercup.h"
using namespace std;

void printPath(vector<int> path, int level)
{
    for(int i = level; i < path.size(); ++i)
	cout << path[i] << " ";
    cout << endl;
}

void findSum(TreeNode *root, int sum, vector<int> path, int level)
{
    if(!root)
	return;
    path.push_back(root->val);
    int tmp = 0;
    for(int i = level; i >= 0; --i)
    {
	tmp += path[i];
	if(tmp == sum)
	    printPath(path, i);
    }
    vector<int> path1(path), path2(path);
    findSum(root->left, sum, path1, level+1);
    findSum(root->right, sum, path2, level+1);
}

int main()
{
    int sum = 6;
    vector<int> path;
    int a[] = {1, 2, 3, 1, 2, 4, 1};

    TreeNode *root = buildBST(a, 0, 6);
    findSum(root, sum, path, 0);

    return 0;
}
