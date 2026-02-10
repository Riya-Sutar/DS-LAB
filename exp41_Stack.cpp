#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    void del() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
        cout << "Stack deleted" << endl;
    }

    int top() {
        if (topNode != nullptr) return topNode->data;
        return -1;
    }

    bool empty() {
        return topNode == nullptr;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    s.pop();
    cout << "After pop: " << s.top() << endl;

    s.del();

    if (s.empty()) {
        cout << "Stack is empty" << endl;
    }

    return 0;
}
