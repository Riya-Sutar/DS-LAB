## 9) BST traversals

#include <bits/stdc++.h>
using namespace std;

struct Node{ int d; Node *l,*r; Node(int x){d=x;l=r=NULL;} };

Node* insert(Node* root,int x){
    if(!root) return new Node(x);
    if(x<root->d) root->l=insert(root->l,x);
    else root->r=insert(root->r,x);
    return root;
}
void in(Node* root){ if(!root) return; in(root->l); cout<<root->d<<" "; in(root->r); }

int main() {
    Node *root=NULL; int n,x; cin>>n;
    while(n--){ cin>>x; root=insert(root,x); }
    in(root);
}
