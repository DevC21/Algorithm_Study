#include<bits/stdc++.h>
using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

// ���� Ʈ���� ���� ��ȸ(Level-order Traversal)
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

// ���� ��ȸ(Preorder Traversal)
// DFS�� �湮������ ����
void preorder(int cur){ // preorder(1);
    cout << cur << ' ';
    if(lc[cur]) preorder(lc[cur]);
    if(rc[cur]) preorder(rc[cur]);
}

// ���� ��ȸ(Inorder Traversal)
// Ʈ���� ���� Ž�� Ʈ�����ٸ� �ڿ������� ũ�� ������ �湮
void inorder(int cur){ // inorder(1);
    if(lc[cur]) inorder(lc[cur]);
    cout << cur << ' ';
    if(rc[cur]) inorder(rc[cur]);
}

// ���� ��ȸ(Postorder Traversal)
void postorder(int cur){ // postorder(1);
    if(lc[cur]) postorder(lc[cur]);
    if(rc[cur]) postorder(rc[cur]);
    cout << cur << ' ';
}