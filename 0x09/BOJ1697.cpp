#include<bits/stdc++.h>
using namespace std;

int dist[100005];
int dx[3] = {1,-1,2};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist+100005, -1);

    queue<int> Q;
    int n, k;

    cin >> n >> k;

    dist[n] = 0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == k){
            cout << dist[cur];
            return 0;
        }
        for(int i = 0; i < 3; i++){
            int nx;
            if( i < 2)
                nx = cur + dx[i];
            else
                nx = cur * dx[i];
            if(nx < 0 || nx >= 100005)
                continue;
            if(dist[nx] >= 0)
                continue;
            if(nx == k){
                cout << dist[cur] + 1;
                return 0;
            }
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
}