#include<bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
int indegree[32005];
priority_queue<int, vector<int>, greater<int>> pq;

/*
  ���� 3�� "�����ϸ� ���� ����"(��ȣ�� ���� ���� ����)�� ���� �Ϸ���
  ť�� ���ÿ� ���� ���Ұ� ���� ��, ���� ���� ���Ҹ� ���� �������� �ϹǷ�
  �ּ� ���� ����ؾ� �Ѵ�.
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indegree[b]++;
    }

    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0)
            pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt] == 0){
                pq.push(nxt);
            }
        }
    }
}