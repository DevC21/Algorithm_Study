#include<bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
vector<int> ans;
int indegree[32005];
queue<int> q;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indegree[b]++;
    }

    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        for(auto nxt : adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt] == 0)
                q.push(nxt);
        }       
    }

    for(auto nxt : ans)
        cout << nxt << ' ';
}