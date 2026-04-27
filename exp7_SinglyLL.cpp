7) Singly linked list

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; Node* next;
    Node(int x){ data=x; next=NULL; }
};

int main() {
    Node *head=NULL, *temp, *nn;
    int n, x;
    cin >> n;
    while(n--) {
        cin >> x;
        nn = new Node(x);
        if(!head) head=nn, temp=nn;
        else temp->next=nn, temp=nn;
    }
    for(temp=head; temp; temp=temp->next) cout << temp->data << " ";
}
