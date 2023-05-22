#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define X first
#define Y second

int n, m, a, b;
ll c;
ll INF = INT64_MAX / 2;
vector<pair<ll, int>> adj[100005];
ll t[100005];

// ������ �ּڰ� st = 1, en = �Է� ���� ������ ����ġ �� �ִ밪
ll st = 1, en;

bool Dijkstra(ll limit){
    priority_queue< pair<ll, int>,
                    vector<pair<ll, int>>,
                    greater<pair<ll, int>> > pq;

    fill(t, t+n+1, INF);

    t[a] = 0;
    pq.push({t[a], a});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(t[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            //���� ��� ���Ѻ��� ū ����� ������ ������� �ʵ��� �Ѵ�.
            if(nxt.X > limit) continue;
            if(t[nxt.Y] > t[cur.Y] + nxt.X){
                t[nxt.Y] = t[cur.Y] + nxt.X;
                pq.push({t[nxt.Y], nxt.Y});
            }
        }
    }

/*
    ���ͽ�Ʈ�� �˰����� ������ ��,
    �������� �ּ� ���� ���� �� C�� ����
    ��ǥ ������ ������ �� �ִ��� �Ǵ��Ѵ�.
*/
    if(t[b] > c) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a >> b >> c;

    for(int i = 0; i < m; i++){
        int u, v;
        ll cost;
        cin >> u >> v >> cost;

        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
        en = max(en, cost);
    }
    // �̺� Ž���� �̿��� �ִ� ����� �ּڰ��� ã�´�.
    while(st < en) {
        ll mid = (st + en) / 2;
        if(Dijkstra(mid)) en = mid;
        else st = mid + 1;
    }

    if(Dijkstra(st)) cout << st;
    else cout << -1;
}