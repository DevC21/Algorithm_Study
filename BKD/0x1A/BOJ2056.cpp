#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
int dp[10005];
map<int, int> m;
int indegree[10005];
queue<int> q;
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int time, tasks;
        cin >> time >> tasks;
        dp[i] = time;
        m[i] = time;
        indegree[i] = tasks;
        if(indegree[i] == 0){
            q.push(i);
        }
        for(int j = 0; j < tasks; j++){
            int v;
            cin >> v;

            adj[v].push_back(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur]){
            dp[nxt] = max(dp[nxt], dp[cur]+m[nxt]);
            indegree[nxt]--;
            if(indegree[nxt] == 0)
                q.push(nxt);
        }
    }

    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}