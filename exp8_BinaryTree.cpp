8) Binary tree traversals

#include <bits/stdc++.h>
using namespace std;

struct Node{ int d; Node *l,*r; Node(int x){d=x;l=r=NULL;} };

void pre(Node* root){ if(!root) return; cout<<root->d<<" "; pre(root->l); pre(root->r); }
void in(Node* root){ if(!root) return; in(root->l); cout<<root->d<<" "; in(root->r); }
void post(Node* root){ if(!root) return; post(root->l); post(root->r); cout<<root->d<<" "; }

int main() {
    Node *root=new Node(1);
    root->l=new Node(2); root->r=new Node(3);
    pre(root); cout<<"\n"; in(root); cout<<"\n"; post(root);
}
