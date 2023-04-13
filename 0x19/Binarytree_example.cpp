#include<bits/stdc++.h>
using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

// 이진 트리의 레벨 순회(Level-order Traversal)
void bfs() { // root = 1
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        if(lc[cur]) q.push(lc[cur]);
        if(rc[cur]) q.push(rc[cur]);
    }
}

// 전위 순회(Preorder Traversal)
// DFS와 방문순서가 동일
void preorder(int cur){ // preorder(1);
    cout << cur << ' ';
    if(lc[cur]) preorder(lc[cur]);
    if(rc[cur]) preorder(rc[cur]);
}

// 중위 순회(Inorder Traversal)
// 트리가 이진 탐색 트리였다면 자연스럽게 크기 순으로 방문
void inorder(int cur){ // inorder(1);
    if(lc[cur]) inorder(lc[cur]);
    cout << cur << ' ';
    if(rc[cur]) inorder(rc[cur]);
}

// 후위 순회(Postorder Traversal)
void postorder(int cur){ // postorder(1);
    if(lc[cur]) postorder(lc[cur]);
    if(rc[cur]) postorder(rc[cur]);
    cout << cur << ' ';
}