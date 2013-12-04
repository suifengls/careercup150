#include "../careercup.h"
using namespace std;

struct Node
{
    int val;
    Node *ptr1, *ptr2;
    Node(int x): val(x), ptr1(NULL), ptr2(NULL) {}
};

Node *Clone(Node *root, unordered_map<Node*, Node*> &hm)
{
    if(!root) return NULL;
    auto it = hm.find(root);
    if(it != hm.end()) return it->second;
    Node *node = new Node(root->val);
    hm[root] = node;
    node->ptr1 = Clone(root->ptr1, hm);
    node->ptr2 = Clone(root->ptr2, hm);
    return node;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    n1->ptr1 = n2;
    n1->ptr2 = n3;
    n2->ptr1 = n2;
    n3->ptr1 = n1;
    n3->ptr2 = n2;

    unordered_map <Node*, Node*> hm;
    Clone(n1, hm);
    return 0;
}
