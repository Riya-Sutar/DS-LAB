## 11) BFS and DFS

#include <bits/stdc++.h>
using namespace std;

vector<int> g[^100];
bool vis[^100];

void dfs(int u){
    vis[u]=1; cout<<u<<" ";
    for(int v:g[u]) if(!vis[v]) dfs(v);
}

int main() {
    int n,e,u,v; cin>>n>>e;
    while(e--){ cin>>u>>v; g[u].push_back(v); g[v].push_back(u); }

    queue<int> q; q.push(0); vis[^0]=1;       // BFS
    while(!q.empty()){
        int x=q.front(); q.pop(); cout<<x<<" ";
        for(int y:g[x]) if(!vis[y]) vis[y]=1, q.push(y);
    }

    cout << "\n";
    memset(vis,0,sizeof(vis));
    dfs(0);
}
