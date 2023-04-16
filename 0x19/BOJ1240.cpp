#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[1005];
int dist[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n-1; i++){
        int u, v, dis;
        cin >> u >> v >> dis;

        adj[u].push_back({v, dis});
        adj[v].push_back({u, dis});
    }

    while(m--){
        int u, v;
        cin >> u >> v;

        fill(dist+1, dist+n+1, -1);
        queue<int> q;
        q.push(u);
        dist[u] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(dist[nxt.first] != -1)
                    continue;
                q.push(nxt.first);
                dist[nxt.first] = dist[cur] + nxt.second;
            }
        }

        cout << dist[v] << '\n';
    }
}