#include<bits/stdc++.h>
using namespace std;

int parent[1000005];

// �θ� ��带 ã�� �Լ�
int getParent(int parent[], int x) {
    if(parent[x] == x)  return x;
    return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) 
        parent[b] = a;
    else
        parent[a] = b;
}

// ���� �θ� �������� Ȯ��
int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++)
        parent[i] = i;

    for(int i = 0; i < m; i++){
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if(cmd == 0){
            unionParent(parent, a, b);
        }
        else{
            if(findParent(parent, a, b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
}