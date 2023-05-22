#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int indegree[100];
queue<int> q;
vector<int> result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        result.push_back(cur);
        q.pop();
        for(int nxt : adj[cur]){
            if(indegree[nxt] != 0)
                indegree[nxt]--;
            if(indegree[nxt] == 0)
                q.push(nxt);
        }
    }

    if(result.size() != n)
        cout << "cycle exists";
    else{
        for(auto x : result)
            cout << char(x + 'A' - 1) << ' ';
    }
}