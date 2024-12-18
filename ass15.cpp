#include <iostream>
#include <string>

using namespace std;

struct Node {
    string title;
    int pageCount;
    Node* firstChild;
    Node* nextSibling;

    Node(string t, int p) : title(t), pageCount(p), firstChild(nullptr), nextSibling(nullptr) {}
};

bool isEmpty(Node* root) {
    return root == nullptr;
}

int countChapters(Node* root) {
    if (root == nullptr) return 0;
    int count = 0;
    if (root->firstChild != nullptr && root->nextSibling == nullptr) {
        count++;
    }
    count += countChapters(root->firstChild);
    count += countChapters(root->nextSibling);
    return count;
}

Node* findLongestChapter(Node* root, Node*& maxChapter) {
    if (root == nullptr) return maxChapter;
    if (root->firstChild == nullptr && root->pageCount > maxChapter->pageCount) {
        maxChapter = root;
    }
    findLongestChapter(root->firstChild, maxChapter);
    findLongestChapter(root->nextSibling, maxChapter);
    return maxChapter;
}

Node* deleteNode(Node* root, const string& target) {
    if (root == nullptr) return nullptr;
    if (root->title == target) {
        delete root;
        return nullptr;
    }
    root->firstChild = deleteNode(root->firstChild, target);
    root->nextSibling = deleteNode(root->nextSibling, target);
    return root;
}

void printTree(Node* root, int level = 0) {
    if (root == nullptr) return;
    for (int i = 0; i < level; i++) cout << "-";
    cout << root->title << " (" << root->pageCount << " trang)" << endl;
    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

int main() {
    Node* root = new Node("Cay muc luc", 0);

    root->firstChild = new Node("Chuong 1", 50);
    root->firstChild->nextSibling = new Node("Chuong 2", 80);
    root->firstChild->nextSibling->nextSibling = new Node("Chuong 3", 30);

    root->firstChild->firstChild = new Node("Muc 11", 20);
    root->firstChild->firstChild->nextSibling = new Node("Muc 12", 30);

    root->firstChild->nextSibling->firstChild = new Node("Muc 21", 40);
    root->firstChild->nextSibling->firstChild->nextSibling = new Node("Muc 22", 40);

    cout << "Cay muc luc sach" << endl;
    printTree(root);

    cout << "So chuong cua sach: " << countChapters(root) << endl;

    Node* maxChapter = new Node("", 0);
    findLongestChapter(root, maxChapter);
    cout << "Chuong dai nhat: " << maxChapter->title << " voi " << maxChapter->pageCount << " trang" << endl;

    string target;
    cout << "Nhap ten muc can xoa: ";
    cin >> target;
    root = deleteNode(root, target);

    cout << "Cay sau khi xoa" << endl;
    printTree(root);

    return 0;
}
