#include<bits/stdc++.h>
using namespace std;

vector<int> p(305, -1);

// �θ� ��带 ã�� �Լ�
int getP(int x) {
    if(p[x] < 0)  return x;
    return p[x] = getP(p[x]);
}

// ���� �θ� �������� Ȯ��
int findP(int u, int v){
    u = getP(u); 
    v = getP(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int v, e;
// {���, ����1, ���� 2}
tuple<int, int, int> edge[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;

    for(int i = 1; i <= v; i++){
        int cost;
        cin >> cost;
        edge[e++] = {cost, i, v+1};
    }

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            int cost;
            cin >> cost;
            if(i >= j)
                continue;
            edge[e++] = {cost, i, j};
        }
    }

    v++;
    sort(edge, edge+e);

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!findP(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v-1) break;
    }
    cout << ans;
}