#include <bits/stdc++.h>

using namespace std;

struct Node {
    string title;
    int index;
    int pageCount;
    vector<Node*> children;

    Node(string t, int idx, int pages) : title(t), index(idx), pageCount(pages) {}
};

int countChapters(Node* root) {
    if (root == nullptr) return 0;
    if (root->children.empty()) return 1;
    int count = 0;
    for (auto child : root->children) {
        count += countChapters(child);
    }
    return count;
}

Node* findLongestChapter(Node* root) {
    if (root == nullptr || root->children.empty()) return nullptr;
    
    Node* longest = nullptr;
    int maxPages = 0;
    
    for (auto child : root->children) {
        if (child->pageCount > maxPages) {
            maxPages = child->pageCount;
            longest = child;
        }
        Node* subLongest = findLongestChapter(child);
        if (subLongest && subLongest->pageCount > maxPages) {
            maxPages = subLongest->pageCount;
            longest = subLongest;
        }
    }
    
    return longest;
}

void deleteSection(Node*& root, int sectionIndex) {
    if (root == nullptr) return;

    for (auto it = root->children.begin(); it != root->children.end(); ++it) {
        if ((*it)->index == sectionIndex) {
            root->children.erase(it);
            return; // Muc da duoc xoa
        }
        deleteSection(*it, sectionIndex); // Tiep tuc tim trong cac muc con
    }
}

void printChapterHeadings(Node* chapter) {
    if (chapter == nullptr) return;

    cout << chapter->title << endl;

    for (auto section : chapter->children) {
        printChapterHeadings(section);
    }
}

int main() {
    Node* book = new Node("Book Title", 0, 0);
    
    book->children.push_back(new Node("Chapter 1", 1, 10));
    book->children.push_back(new Node("Chapter 2", 2, 20));
    
    book->children[0]->children.push_back(new Node("Section 1.1", 3, 5));
    
    cout << "So chuong: " << countChapters(book) << endl;

    Node* longestChapter = findLongestChapter(book);
    if (longestChapter != nullptr) {
        cout << "Chuong dai nhat: " << longestChapter->title << endl;
    }

    deleteSection(book, 3);

    printChapterHeadings(book->children[0]);

    // Giai phong bo nho
    // ...

    return 0;
}
