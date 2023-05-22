#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int p[100005];
int dp[100005];
int u;

int DFS(int cur){
    for(int nxt : adj[cur]) {
        if (p[cur] == nxt)
            continue;
        p[nxt] = cur;
        dp[cur] += DFS(nxt);
    }

    return dp[cur];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, q;

    cin >> n >> r >> q;

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(dp+1, dp+100005, 1);

    DFS(r);

    while(q--){
        cin >> u;
        cout << dp[u] << '\n';
    }
}