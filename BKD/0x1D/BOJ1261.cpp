#include<bits/stdc++.h>
using namespace std;

int n, m;
int INF = INT32_MAX / 2;

int D[105][105];
int wall[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

priority_queue< tuple<int, int, int>,
                vector<tuple<int, int, int>>,
                greater<tuple<int, int, int>> > pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 1; i <= n; i++){
        string line;
        cin >> line;
        for(int j = 1; j <= m; j++){
            wall[i][j] = line[j-1] - '0';
        }
    }

    for(int i = 1; i <= n; i++)
        fill(D[i]+1, D[i]+m+1, INF);
    
    D[1][1] = 0;
    pq.push({0, 1, 1});
    while(!pq.empty()){
        int curw, curx, cury;
        tie(curw, curx, cury) = pq.top();
        pq.pop();
        if(D[curx][cury] != curw) continue;

        for(int dir = 0; dir < 4; dir++){
            int nx = curx + dx[dir];
            int ny = cury + dy[dir];
            if(nx > n || nx < 1) continue;
            if(ny > m || ny < 1) continue;
            int nw = curw + wall[nx][ny];
            if(nw < D[nx][ny]) {
                D[nx][ny] = nw;
                pq.push({nw, nx, ny});
            }
        }
    }
    cout << D[n][m];
}