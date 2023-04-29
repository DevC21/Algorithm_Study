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
            uphill++; // ���������� ���� ����
        cnt++;
        if(cnt == n) break; // �Ա��� �����ϱ� ������, ������ ������ n���� �Ǿ����
    }
    
    return uphill * uphill;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // �Ա�(0) ���� �����ϱ⶧���� ������ ������ m+1��
    for(int i = 0; i < m + 1; i++){
        int a, b, c;
        cin >> a >> b >> c;

        // ���������̸� ���� ����� ����
        int w = (c == 0) ? 100 : 1;
        edge[e++] = {w, a, b};
    }

    sort(edge, edge+e); // ���������� ���� �����ϵ��� ��������
    int Min = MST();

    sort(edge, edge+e, greater<>()); // ���������� ���� �����ϵ��� ��������
    int Max = MST();

    cout << Max - Min;
}