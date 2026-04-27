## 5) Stack using array


#include <bits/stdc++.h>
using namespace std;

int st[^100], top=-1;

int main() {
    int ch, x;
    while(cin >> ch) {
        if(ch==1) { cin >> x; st[++top]=x; }     // push
        else if(ch==2 && top!=-1) top--;        // pop
        else if(ch==3 && top!=-1) cout << st[top] << "\n"; // peek
        else if(ch==4) break;
    }
}
