#include<bits/stdc++.h>
using namespace std;

vector<int> adj[20005];
int dist[20005];
vector<int> ans;
int Max = -1;

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

    fill(dist+1, dist+n+1, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] != -1)
                continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
            if(dist[nxt] > Max){
                ans.clear();
                Max = dist[nxt];
                ans.push_back(nxt);
            }
            else if(dist[nxt] == Max){
                ans.push_back(nxt);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << *ans.begin() << ' ' << Max << ' ' << ans.size();
}