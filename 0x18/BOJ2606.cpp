#include<bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool vis[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;
    int ans = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt])
                continue;
            q.push(nxt);
            ans++;
            vis[nxt] = true;
        }
    }

    cout << ans;
}