6) Queue using array

#include <bits/stdc++.h>
using namespace std;

int q[^100], f=0, r=-1;

int main() {
    int ch, x;
    while(cin >> ch) {
        if(ch==1) { cin >> x; q[++r]=x; }       // enqueue
        else if(ch==2 && f<=r) f++;             // dequeue
        else if(ch==3 && f<=r) cout << q[f]<<"\n"; // front
        else if(ch==4) break;
    }
}
