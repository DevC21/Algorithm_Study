#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];
int n, m, start;

void DFS(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
        if(vis[nxt])
            continue;
        DFS(nxt);
    }
}

void BFS() {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()){
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt])
                continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> start;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    DFS(start);
    cout << '\n';
    fill(vis+1, vis+n+1, false);
    BFS();
}