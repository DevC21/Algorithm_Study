#include<bits/stdc++.h>
using namespace std;

int parent[1000005];

// 부모 노드를 찾는 함수
int getParent(int parent[], int x) {
    if(parent[x] == x)  return x;
    return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) 
        parent[b] = a;
    else
        parent[a] = b;
}

// 같은 부모를 가지는지 확인
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