#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t[10005];
int INF = INT32_MAX / 2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        vector<pair<int, int>> adj[10005];
        priority_queue< pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>> > pq;
        int cnt = 0, ans = 0;
        int n, d, c;
        cin >> n >> d >> c;
        fill(t, t+n+1, INF);
        for(int i = 0; i < d; i++){
            int a, b, s;
            cin >> a >> b >> s;

            adj[b].push_back({s, a});
        }

        t[c] = 0;
        pq.push({t[c], c});
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
            if(t[i] != INF){
                cnt++;
                ans = max(ans, t[i]);
            }
        }
        cout << cnt << ' ' << ans << '\n';
    }
}