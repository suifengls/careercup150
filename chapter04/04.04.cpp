#include "../careercup.h"
using namespace std;

vector<vector<int> > visitLevel0(TreeNode *root)
{
    vector<vector<int> > levels;
    vector<int> lv;
    if(!root)
	return levels;
    queue<TreeNode *> q;
    q.push(root);
    int i = 0, j = 0, k = 1;
    vector<int> count;
    count.push_back(k);
    while(!q.empty())
    {
	TreeNode *node = q.front();
	q.pop();
	if(node->left)
	{
	    ++k;
	    q.push(node->left);
	}
	if(node->right)
	{
	    ++k;
	    q.push(node->right);
	}
	lv.push_back(node->val);
	++i;
	if(i == count[j])
	{
	    ++j;
	    count.push_back(k);
	    levels.push_back(lv);
	    lv.clear();
	}
    }
    return levels;
}

vector<vector<TreeNode*> > visitLevel1(TreeNode *root)
{
    vector<vector<TreeNode*> > levels;
    vector<TreeNode*> lv;
    if(!root)
	return levels;
    int l = 0;
    lv.push_back(root);
    levels.push_back(lv);
    while(!levels[l].empty())
    {
	lv.clear();
	for(vector<TreeNode*>::iterator it = levels[l].begin(); it != levels[l].end(); ++it)
	{
	    if((*it)->left)
		lv.push_back((*it)->left);
	    if((*it)->right)
		lv.push_back((*it)->right);
	}
	levels.push_back(lv);
	++l;
    }
    return levels;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode *root = buildBST(a, 0, 8);
    vector<vector<int> > levels = visitLevel0(root);

    for(int i = 0; i < levels.size(); ++i)
    {
	cout << "Level " << i << endl;
	for(int j = 0; j < levels[i].size(); ++j)
	    cout << levels[i][j] << " ";
	cout << endl;
    }

    vector<vector<TreeNode*> > levels1 = visitLevel1(root);
    for(int i = 0; i < levels1.size(); ++i)
    {
	cout << "Level " << i << endl;
	for(int j = 0; j < levels1[i].size(); ++j)
	    cout << levels1[i][j]->val << " ";
	cout << endl;
    }

    return 0;
}
