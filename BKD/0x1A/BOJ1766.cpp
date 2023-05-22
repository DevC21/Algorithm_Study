#include<bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
int indegree[32005];
priority_queue<int, vector<int>, greater<int>> pq;

/*
  조건 3인 "가능하면 쉬운 문제"(번호가 제일 작은 문제)를 만족 하려면
  큐에 동시에 여러 원소가 있을 때, 제일 작은 원소를 먼저 내보내야 하므로
  최소 힙을 사용해야 한다.
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