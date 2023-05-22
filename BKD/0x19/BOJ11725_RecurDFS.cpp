#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int p[100005];

void DFS(int cur){
    for(int nxt : adj[cur]) {
        if (p[cur] == nxt)
            continue;
        p[nxt] = cur;
        DFS(nxt); // Recursion
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1);
    
    for(int i = 2; i <= n; i++){
        cout << p[i] << '\n';
    }
}