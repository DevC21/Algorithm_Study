#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, e;
int v1, v2;
int ans;
int INF = INT32_MAX / 2;
vector<pair<int, int>> adj[805];
priority_queue< pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>> > pq;
int t[805];
int tv1[805];
int tv2[805];

void dijkstra(int i, int table[]){
    fill(table, table+n+1, INF);
    table[i] = 0;
    pq.push({table[i], i});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(table[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(table[nxt.Y] > table[cur.Y] + nxt.X){
                table[nxt.Y] = table[cur.Y] + nxt.X;
                pq.push({table[nxt.Y], nxt.Y});
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cin >> v1 >> v2;

    dijkstra(1, t);
    dijkstra(v1, tv1);
    dijkstra(v2, tv2);

    ans = min(t[v1] + tv1[v2] + tv2[n], t[v2] + tv2[v1] + tv1[n]);

    if(ans >= INF || ans < 0) cout << "-1";
    else cout << ans;
}