#include<bits/stdc++.h>
using namespace std;

int v, e;
int ans;
// {���, ���� ��ȣ}
vector<pair<int, int>> adj[10005];
// chk[i] : i ��° ������ �ּ� ���� Ʈ���� �����ִ°�?
bool chk[10005];
int cnt = 0; // ���� ���õ� ������ ��
priority_queue< tuple<int,int,int>, 
                vector<tuple<int,int,int>>, 
                greater<tuple<int,int,int>> > pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;

    for(int i = 0; i < e; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
    }
    
    chk[1] = 1;
    for(auto nxt : adj[1])
        pq.push({nxt.first, 1, nxt.second});

    while(cnt < v - 1){
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if(chk[b]) continue;
        ans += cost;
        chk[b] = 1;
        cnt++;
        for(auto nxt: adj[b]){
            if(!chk[nxt.second])
                pq.push({nxt.first, b, nxt.second});
        }
    }

    cout << ans;
}