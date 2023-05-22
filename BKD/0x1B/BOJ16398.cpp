#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p(1005, -1);

// �θ� ��带 ã�� �Լ�
int getP(int x) {
    if(p[x] < 0)  return x;
    return p[x] = getP(p[x]);
}

// ���� �θ� �������� Ȯ���ϰ� ��ġ��
int merge(int u, int v){
    u = getP(u); 
    v = getP(v);
    if(u == v) return 0;
    // �� ��带 ��ġ�� �κ�
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int v, e;
// {���, ����1, ���� 2}
tuple<ll, int, int> edge[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cost;
            cin >> cost;
            edge[e++] = {cost, i, j};
        }
    }

    sort(edge, edge+e);
    int cnt = 0;
    ll ans = 0;
    for(int i = 0; i < e; i++){
        int a, b;
        ll cost;
        tie(cost, a, b) = edge[i];
        if(!merge(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v-1) break;
    }
    cout << ans;
}