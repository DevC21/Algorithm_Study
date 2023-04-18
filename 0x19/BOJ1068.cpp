#include<bits/stdc++.h>
using namespace std;

int e;
int ans;
vector<int> adj[51];
int p[51];
int depth[51];
int edepth = 51;
bool done = false;

//DFS로 탐색하면서 노드와 그 모든 자손을 삭제
void deldfs(int cur){
    if(done)
        return;
    if(cur == e)
        edepth = depth[cur];
    for(int nxt : adj[cur]) {
        if (p[cur] == nxt)
            continue;
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        deldfs(nxt);
    }
    if(cur == e)
        done = true;
    if(depth[cur] >= edepth){
        adj[p[cur]].erase(remove(adj[p[cur]].begin(), adj[p[cur]].end(), cur), adj[p[cur]].end());
        adj[cur].clear();
    }
}

//bool leaf로 리프 노드인지 판정
void dfs(int cur){
    bool leaf = true;
    for(int nxt : adj[cur]) {
        if (p[cur] == nxt)
            continue;
        leaf = false;
        p[nxt] = cur;
        dfs(nxt);
    }
    if(leaf){
        ans++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, root;
    cin >> n;

    for(int i = 0; i < n; i++){
        int parent;
        cin >> parent;

        if(parent != -1){
            adj[i].push_back(parent);
            adj[parent].push_back(i);
        }
        else
            root = i;
        p[i] = parent;
    }

    cin >> e;

    // e와 root가 같으면 리프노드는 0 이므로 예외처리
    if(e == root){
        cout << 0;
    }
    else{
        deldfs(root);
        dfs(root);
        cout << ans;
    }
}