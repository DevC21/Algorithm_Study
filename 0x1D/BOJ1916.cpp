#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, st, en;
int INF = INT32_MAX / 2;
vector<pair<int, int>> adj[1005];
int t[1005];
priority_queue< pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>> > pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    fill(t, t+n+1, INF);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    cin >> st >> en;

    t[st] = 0;
    pq.push({t[st], st});
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

    cout << t[en];

}