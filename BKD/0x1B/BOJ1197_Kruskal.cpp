#include<bits/stdc++.h>
using namespace std;

vector<int> p(10005, -1);

// �θ� ��带 ã�� �Լ�
int getP(int x) {
    if(p[x] < 0)  return x;
    return p[x] = getP(p[x]);
}

// ���� �θ� �������� Ȯ��
int findP(int a, int b){
    a = getP(a);
    b = getP(b);
    if(a == b) return 0;
    if(p[a] > p[b]) swap(a, b);
    p[a] += p[b];
    p[b] = a;
    return 1;
}

int v, e;
// {���, ����1, ���� 2}
tuple<int, int, int> edge[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

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