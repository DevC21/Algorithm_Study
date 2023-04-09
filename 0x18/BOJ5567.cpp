#include<bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int vis[505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    int ans = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt] > 0)
                continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
            if(vis[nxt] <= 3)
                ans++;
        }
    }

    cout << ans;
}