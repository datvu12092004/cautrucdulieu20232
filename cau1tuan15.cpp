#include<bits/stdc++.h>
using namespace std;

struct Node {
    int sbd;
    string hoTen;
    Node *left;
    Node *right;

    Node(int s, string h, Node *l, Node *r) : sbd(s), hoTen(h), left(l), right(r) {}
};

class BSTree {
private:
    Node *root;

    void makeEmpty(Node *&t) {
        if (t == nullptr) return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }

    void insert(int sbd, string hoTen, Node *&t) {
        if (t == nullptr)
            t = new Node(sbd, hoTen, nullptr, nullptr);
        else if (sbd < t->sbd)
            insert(sbd, hoTen, t->left);
        else if (sbd > t->sbd)
            insert(sbd, hoTen, t->right);
    }

    Node *search(int sbd, Node *t) {
        if (t == nullptr) return nullptr;
        if (sbd < t->sbd) return search(sbd, t->left);
        else if (sbd > t->sbd) return search(sbd, t->right);
        else return t;
    }

    void preorder(Node *t) {
        if (t != nullptr) {
            cout << t->sbd << " - " << t->hoTen << endl;
            preorder(t->left);
            preorder(t->right);
        }
    }

    void inorder(Node *t) {
        if (t != nullptr) {
            inorder(t->left);
            cout << t->sbd << " - " << t->hoTen << endl;
            inorder(t->right);
        }
    }

    void postorder(Node *t) {
        if (t != nullptr) {
            postorder(t->left);
            postorder(t->right);
            cout << t->sbd << " - " << t->hoTen << endl;
        }
    }

    void treeToVector(Node *t, vector<Node*> &vec) {
        if (t != nullptr) {
            treeToVector(t->left, vec);
            vec.push_back(t);
            treeToVector(t->right, vec);
        }
    }

    void heapify(vector<Node*> &vec, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && vec[left]->sbd > vec[largest]->sbd)
            largest = left;

        if (right < n && vec[right]->sbd > vec[largest]->sbd)
            largest = right;

        if (largest != i) {
            swap(vec[i], vec[largest]);
            heapify(vec, n, largest);
        }
    }

    void heapSort(vector<Node*> &vec) {
        int n = vec.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(vec, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(vec[0], vec[i]);
            heapify(vec, i, 0);
        }
    }

public:
    BSTree() : root(nullptr) {}

    ~BSTree() {
        makeEmpty(root);
    }

    bool isEmpty() {
        return root == nullptr;
    }

    void makeEmpty() {
        makeEmpty(root);
    }

    void insert(int sbd, string hoTen) {
        insert(sbd, hoTen, root);
    }

    Node *search(int sbd) {
        return search(sbd, root);
    }

    void preorder() {
        preorder(root);
    }

    void inorder() {
        inorder(root);
    }

    void postorder() {
        postorder(root);
    }

    void sortStudents() {
        vector<Node*> vec;
        treeToVector(root, vec);
        heapSort(vec);
        for (Node* n : vec) {
            cout << n->sbd << " - " << n->hoTen << endl;
        }
    }
};

int main() {
    BSTree bst;
    bst.insert(5, "Tuan");
    bst.insert(6, "Lan");
    bst.insert(3, "Cong");
    bst.insert(8, "Huong");
    bst.insert(7, "Binh");
    bst.insert(4, "Hai");
    bst.insert(2, "Son");

    Node *n1 = bst.search(4);
    Node *n2 = bst.search(9);

    if (n1 != nullptr)
        cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
    if (n2 == nullptr)
        cout << "Khong tim thay sinh vien voi SBD=9" << endl;

    cout << "Duyet cay theo thu tu truoc:" << endl;
    bst.preorder();

    cout << "Duyet cay theo thu tu giua:" << endl;
    bst.inorder();

    cout << "Duyet cay theo thu tu sau:" << endl;
    bst.postorder();

    cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    bst.sortStudents();

    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;

    return 0;
}
