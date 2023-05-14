/*
    �� ���ø��� ������ ������ �ִܰŸ��� Ǯ���ϸ� 
    �ð����⵵�� O(VElgE)�� �Ǹ�, V�� E�� 10�� ������ ������ ���� �ð��� ������� ���Ѵ�.

    �׷��� �������� �� ���� ������ �ִܰŸ��� ���ϴ� Ǯ�̷� ������ ��
    ������ �����忡�� ���÷� �����ϱ� ������ 
    ������ �Է¹��� �� ���� ������ �� ������ �ݴ�� �Է� �޾ƾ� �ùٸ� Ǯ�̰� �ȴ�.
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