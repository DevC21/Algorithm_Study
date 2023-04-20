#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int indegree[1005];
queue<int> q;
vector<int> result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int singers, u = 0, v = 0;
        cin >> singers;
        for(int j = 0; j < singers; j++){
            cin >> v;
            if(u != 0){
                adj[u].push_back(v);
                indegree[v]++;
            }
            u = v;
        }
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
        cout << "0";
    else{
        for(auto x : result)
            cout << x << '\n';
    }
}