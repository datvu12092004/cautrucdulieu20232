#include<iostream>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
    Node (int x) {
        key = x;
        left = right = NULL;
    }
};

void printInorder(struct Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

void printPostorder(struct Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->key << " ";
}

void printPreorder(struct Node* node) {
    if (node == NULL)
        return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Duyet cay theo thu tu truoc:\n";
    printPreorder(root);

    cout << "\nDuyet cay theo thu tu giua:\n";
    printInorder(root);

    cout << "\nDuyet cay theo thu tu sau:\n";
    printPostorder(root);

    return 0;
}
