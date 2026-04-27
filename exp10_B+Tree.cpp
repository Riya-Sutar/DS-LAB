#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ORDER = 3; // Max children (m). Max keys = m-1.

struct Node {
    bool leaf;
    vector<int> keys;
    vector<Node*> child;
    Node* next; // For leaf-to-leaf linking

    Node(bool isLeaf = false) : leaf(isLeaf), next(nullptr) {}
};

class BPlusTree {
    Node* root;

    void split(Node* parent, int i, Node* child) {
        Node* newNode = new Node(child->leaf);
        int mid = (ORDER + 1) / 2;

        // Split keys and children
        if (child->leaf) {
            newNode->keys.assign(child->keys.begin() + mid, child->keys.end());
            child->keys.erase(child->keys.begin() + mid, child->keys.end());
            newNode->next = child->next;
            child->next = newNode;
        } else {
            newNode->keys.assign(child->keys.begin() + mid, child->keys.end());
            newNode->child.assign(child->child.begin() + mid, child->child.end());
            int upKey = child->keys[mid - 1]; // Key to promote
            child->keys.erase(child->keys.begin() + mid - 1, child->keys.end());
            child->child.erase(child->child.begin() + mid, child->child.end());
        }

        parent->keys.insert(parent->keys.begin() + i, newNode->keys[0]);
        parent->child.insert(parent->child.begin() + i + 1, newNode);
    }

    void insertNonFull(Node* node, int key) {
        if (node->leaf) {
            auto it = lower_bound(node->keys.begin(), node->keys.end(), key);
            node->keys.insert(it, key);
        } else {
            int i = upper_bound(node->keys.begin(), node->keys.end(), key) - node->keys.begin();
            if (node->child[i]->keys.size() == ORDER) {
                split(node, i, node->child[i]);
                if (key > node->keys[i]) i++;
            }
            insertNonFull(node->child[i], key);
        }
    }

public:
    BPlusTree() { root = new Node(true); }

    void insert(int key) {
        if (root->keys.size() == ORDER) {
            Node* s = new Node(false);
            s->child.push_back(root);
            split(s, 0, root);
            root = s;
        }
        insertNonFull(root, key);
    }

    bool search(int key) {
        Node* curr = root;
        while (!curr->leaf) {
            int i = upper_bound(curr->keys.begin(), curr->keys.end(), key) - curr->keys.begin();
            curr = curr->child[i];
        }
        return binary_search(curr->keys.begin(), curr->keys.end(), key);
    }
};

int main() {
    BPlusTree tree;
    for (int k : {10, 20, 5, 6, 12, 30, 7, 17}) tree.insert(k);
    cout << "Search 12: " << (tree.search(12) ? "Found" : "Not Found") << endl;
    return 0;
}
