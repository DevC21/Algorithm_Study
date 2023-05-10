#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int INF = INT32_MAX / 2;
vector<pair<int, int>> adj[20005];
int t[20005];
int pre[20005];
priority_queue< pair<int, int>, 
                vector<pair<int,int>>, 
                greater<pair<int, int>> > pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    fill(t, t+n+1, INF);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    int k, e;
    cin >> k >> e;

    t[k] = 0;
    pq.push({t[k], k});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(t[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(t[nxt.Y] > t[cur.Y] + nxt.X){
                t[nxt.Y] = t[cur.Y] + nxt.X;
                pre[nxt.Y] = cur.Y;
                pq.push({t[nxt.Y], nxt.Y});
            }
        }
    }

    cout << t[e] << '\n';

    vector<int> path;
    int cur = e;
    while(cur != k){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for(auto x : path) cout << x << ' ';
}