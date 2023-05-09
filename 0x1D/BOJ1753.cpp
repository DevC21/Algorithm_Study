#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int INF = INT32_MAX / 2;
vector<pair<int, int>> adj[20005];
int t[20005];
priority_queue< pair<int, int>, 
                vector<pair<int,int>>, 
                greater<pair<int, int>> > pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    fill(t, t+n+1, INF);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    t[k] = 0;
    pq.push({t[k], k});
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

    for(int i = 1; i <= n; i++){
        if(t[i] == INF) cout << "INF\n";
        else cout << t[i] << "\n";
    }
}