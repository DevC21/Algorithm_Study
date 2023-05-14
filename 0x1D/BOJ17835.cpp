/*
    각 도시마다 면접장 사이의 최단거리로 풀이하면 
    시간복잡도는 O(VElgE)가 되며, V와 E가 10만 단위기 때문에 제한 시간을 통과하지 못한다.

    그래서 면접장들과 각 도시 사이의 최단거리를 구하는 풀이로 접근할 때
    역으로 면접장에서 도시로 가야하기 때문에 
    간선을 입력받을 때 시작 정점과 끝 정점을 반대로 입력 받아야 올바른 풀이가 된다.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define X first
#define Y second

int n, m, k;
ll INF = INT64_MAX / 2;
ll ansdist = 0;
int anscity = 0;
vector<pair<ll, int>> adj[100005];
ll t[100005];
priority_queue< pair<ll, int>,
                vector<pair<ll, int>>,
                greater<pair<ll, int>> > pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    fill(t, t+n+1, INF);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;

        adj[v].push_back({c, u});
    }

    for(int i = 0; i < k; i++){
        int l;
        cin >> l;

        t[l] = 0;
        pq.push({t[l], l});
    }

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
        if(ansdist < t[i]){
            anscity = i;
            ansdist = t[i];
        }
    }

    cout << anscity << '\n' << ansdist;
}