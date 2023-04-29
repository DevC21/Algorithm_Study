#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p(1005, -1);

int e;
tuple<int, int, int> edge[1000005];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int merge(int u, int v){
    u = find(u); 
    v = find(v);
    if(u == v) return 0;
    if(u < v) p[v] = u;
    else p[u] = v;
    return 1;
}

int MST(){
    fill(p.begin(), p.end(), -1);

    int cnt = 0;
    int uphill = 0;
    for(int i = 0; i < e; i++){
        int w, a, b;
        tie(w, a, b) = edge[i];

        if(!merge(a, b)) continue;
        if(w == 100)
            uphill++; // 오르막길의 개수 증가
        cnt++;
        if(cnt == n) break; // 입구를 포함하기 때문에, 간선의 개수가 n개가 되어야함
    }
    
    return uphill * uphill;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 입구(0) 부터 시작하기때문에 간선의 개수는 m+1개
    for(int i = 0; i < m + 1; i++){
        int a, b, c;
        cin >> a >> b >> c;

        // 오르막길이면 높은 비용을 가짐
        int w = (c == 0) ? 100 : 1;
        edge[e++] = {w, a, b};
    }

    sort(edge, edge+e); // 내리막길을 먼저 선택하도록 간선정렬
    int Min = MST();

    sort(edge, edge+e, greater<>()); // 오르막길을 먼저 선택하도록 간선정렬
    int Max = MST();

    cout << Max - Min;
}