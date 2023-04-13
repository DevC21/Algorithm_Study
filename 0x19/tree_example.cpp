#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];
int p[10];
int depth[10];

// root = 1 �� ������ �θ� ������ p�� ����
void bfs(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]) {
            if (p[cur] == nxt)
                continue;
            q.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] = 1; //�ڽ��� depth�� �θ��� depth + 1��
        }
    }
}

void dfsNonRecur(int root){
    stack<int> s; //queue�� stack���� �ٲٸ� DFS
    s.push(root);
    while (!s.empty()){
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]) {
            if (p[cur] == nxt)
                continue;
            s.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] = 1; //�ڽ��� depth�� �θ��� depth + 1��
        }
    }
}

void dfsRecur(int cur){
    cout << cur << ' ';
    for(int nxt : adj[cur]) {
        if (p[cur] == nxt)
            continue;
        p[nxt] = cur;
        depth[nxt] = depth[cur] = 1;
        dfsRecur(nxt); // ���
    }
}