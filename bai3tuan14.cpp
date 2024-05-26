#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void printPreorder(Node* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPostorder(Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

Node* insertNode(Node* node, int data) {
    if (node == NULL)
        return new Node(data);
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    return node;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);
    cout << "Mang duoc sap xep la: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";

    Node* root = NULL;
    for (int i = 0; i < arr.size(); i++)
        root = insertNode(root, arr[i]);

    cout << "Duyet truoc: ";
    printPreorder(root);
    cout << "\n";

    cout << "Duyet giua: ";
    printInorder(root);
    cout << "\n";

    cout << "Duyet sau: ";
    printPostorder(root);
    cout << "\n";

    return 0;
}
