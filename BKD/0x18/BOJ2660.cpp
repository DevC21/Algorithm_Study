#include<bits/stdc++.h>
using namespace std;

vector<int> adj[51];
vector<int> member[51];
int Min = 51;
int vis[51];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int u, v;

    while(u != -1 && v != -1){
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        fill(vis+1, vis+n+1, 0);
        int score = 0;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt] > 0)
                    continue;
                q.push(nxt);
                vis[nxt] = vis[cur] + 1;
                score = max(score, vis[nxt]);
            }
        }
        score--;
        if(score > 0){
            Min = min(score, Min);
        }
        member[score].push_back(i);
    }

    sort(member[Min].begin(), member[Min].end());

    cout << Min << ' ' <<member[Min].size() << '\n';

    for(auto nxt : member[Min])
        cout << nxt << ' ';
}