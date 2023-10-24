#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree1()
{
    Node *root = new Node(10);
    root->left = new Node(12);
    root->left->left = new Node(8);
    root->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(10);
    return root;
}

Node *createTree2()
{
    Node *root = new Node(10);
    root->left = new Node(12);
    root->left->left = new Node(8);
    root->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(10);
    return root;
}

bool method1(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    return (root1->data == root2->data) && method1(root1->left, root2->left) && method1(root1->right, root2->right);
}

int main()
{
    Node *root1 = createTree1();
    Node *root2 = createTree2();
    cout << method1(root1, root2) << endl;
    return 0;
}