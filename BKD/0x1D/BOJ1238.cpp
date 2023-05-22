#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, x;

int INF = INT32_MAX / 2;
int ans = 0;
vector<pair<int, int>> adj[1005];
int tx[1005];
int t[1005];
priority_queue< pair<int, int>, 
                vector<pair<int,int>>, 
                greater<pair<int, int>> > pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    fill(tx, tx+n+1, INF);

    tx[x] = 0;
    pq.push({tx[x], x});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(tx[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(tx[nxt.Y] > tx[cur.Y] + nxt.X){
                tx[nxt.Y] = tx[cur.Y] + nxt.X;
                pq.push({tx[nxt.Y], nxt.Y});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(i == x) continue;
        fill(t, t+n+1, INF);

        t[i] = 0;
        pq.push({t[i], i});
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            if(t[cur.Y] != cur.X) continue;
            for(auto nxt : adj[cur.Y]){
                if(t[nxt.Y] > t[cur.Y] + nxt.X){
                    t[nxt.Y] = t[cur.Y] + nxt.X;
                    pq.push({t[nxt.Y], nxt.Y});
                }
            }
        }
        ans = max(ans, t[x] + tx[i]);
    }

    cout << ans;

}