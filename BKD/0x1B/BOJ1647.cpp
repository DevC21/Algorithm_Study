#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p(100005, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int merge(int u, int v){
    u = find(u); 
    v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int e;
tuple<ll, int, int> edge[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        edge[e++] = {c, a, b};
    }

    sort(edge, edge+e);
    int cnt = 0;
    ll ans = 0;
    for(int i = 0; i < e; i++){
        int a, b;
        ll cost;
        tie(cost, a, b) = edge[i];
        /* 
            edge는 sort되어 있으므로
            마을은 항상 n-1번 / 1집으로 분리되어야 유지비의 합이 최소가 된다.
            또한 edge가 sort되어 있으면
            n번째 집은 항상 제일 큰 유지비를 가지는 집이다.
            따라서 n-1번째 집까지만 구하면(cnt == n-2)
            정답이 된다.
        */
        if(cnt == n-2) break;
        if(!merge(a, b)) continue;
        ans += cost;
        cnt++;

    }
    cout << ans;
}