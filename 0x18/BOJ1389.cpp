#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int vis[101];
int Min = INT32_MAX;
int MinUser;

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

    for(int i = 1; i <= n; i++){
        fill(vis+1, vis+n+1, 0);

        queue<int> q;
        q.push(i);
        int score = 0;
        vis[i] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt] > 0)
                    continue;
                q.push(nxt);
                vis[nxt] = vis[cur] + 1;
            }
        }
        
        for(int j = 1; j <= n; j++){
            if(i == j)
                continue;
            score += vis[j];
        }

        if(score < Min){
            Min = score;
            MinUser = i;
        }
    }

    cout << MinUser;
}