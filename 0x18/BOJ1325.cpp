#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
vector<int> ans;
int dist[10005];
int Max = -1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adj[b].push_back(a);
    }

    for(int i =  1; i <= n; i++){
        fill(dist+1, dist+n+1, -1);

        int cnt = 0;
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(dist[nxt] != -1)
                    continue;
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
                cnt++;
            }
        }

        if(cnt > Max){
            ans.clear();
            Max = cnt;
            ans.push_back(i);
        }
        else if(cnt == Max){
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    for(auto com : ans){
        cout << com << ' ';
    }
}