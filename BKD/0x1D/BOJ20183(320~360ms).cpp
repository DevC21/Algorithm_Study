#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define X first
#define Y second

vector<pair<ll, int>> adj[10'0005];
// �ִ� ���ݾ�, ������
priority_queue< pair<ll, int>,
                vector<pair<ll, int>>,
                greater<pair<ll, int>> > pq;
// �ִ� ���ݾ�                
ll t[10'0005];
// ���� ���ݾ�
ll cost[10'0005];
ll INF = INT64_MAX / 2;
int n, m, st, en;
ll c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st >> en >> c;

    for (int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    fill(t, t + n + 1, INF);

    pq.push({0, st});
    t[st] = 0;
    while (!pq.empty()){
        ll CURCOST;
        int CUR;
        tie(CURCOST, CUR) = pq.top();
        pq.pop();

        if (CURCOST != t[CUR])
            continue;

        // nxt.X = ������ ����ġ nxt.Y = �������� ��ȣ
        // t[nxt.Y] = st���� nxt.Y������ ���
        for (auto nxt : adj[CUR]){
            // ���� ���ݾװ� ���� ����� ���ݾ��� ���� ���� ���� ������ continue
            if (nxt.X + cost[CUR] > c)
                continue;
            if (t[nxt.Y] <= max(CURCOST, nxt.X))
                continue;
            t[nxt.Y] = max(CURCOST, nxt.X);
            cost[nxt.Y] = cost[CUR] + nxt.X;
            pq.push({t[nxt.Y], nxt.Y});
        }
    }

    if (t[en] > c)
        cout << -1;
    else
        cout << t[en];
}
