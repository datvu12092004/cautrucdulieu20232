#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

struct Node {
    string content;
    Node* left;
    Node* right;

    Node(string cont) : content(cont), left(NULL), right(NULL) {}
};

bool are_identical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 != NULL && root2 != NULL) {
        return (root1->content == root2->content &&
                are_identical(root1->left, root2->left) &&
                are_identical(root1->right, root2->right));
    }
    return false;
}

Node* create_tree(int levels) {
    if (levels == 0) return NULL;
    string content = "Chapter " + to_string(levels);
    Node* node = new Node(content);
    node->left = create_tree(levels - 1);
    node->right = create_tree(levels - 1);
    return node;
}

int main() {
    int N = 3; 
    Node* tree1 = create_tree(N);
    Node* tree2 = create_tree(N);

    auto start = high_resolution_clock::now(); 

    if (are_identical(tree1, tree2)) {
        cout << "Hai cuon sach la ban copy cua nhau" << endl;
    } else {
        cout << "Hai cuon sach khong phai la ban copy cua nhau" << endl;
    }

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Thoi gian thuc thi: " << duration.count() << " giay" << endl;
    return 0;
}
