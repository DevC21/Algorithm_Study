#include <bits/stdc++.h>
using namespace std;
#define X get<1>
#define Y get<2>
#define Z get<0>
int board[102][102][102];
int dist[102][102][102];
int n , m, h; 
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1}; // index 4,5 에서 1은 위쪽 -1은 아래쪽을 의미
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    queue<tuple<int,int,int>> Q;

    for(int l = 0; l < h; l++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                    cin >> board[l][i][j];
                    if(board[l][i][j] == 1)
                        Q.push({l,i,j});
                    if(board[l][i][j] == 0)
                        dist[l][i][j] = -1;
                }

            }
    }

    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; dir++){ 
            int nx = X(cur) + dx[dir];
            int ny = Y(cur) + dy[dir]; 
            int nz = Z(cur) + dz[dir]; 
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue; 
            if(dist[nz][nx][ny] >= 0) 
                continue; 
            dist[nz][nx][ny] = dist[Z(cur)][X(cur)][Y(cur)] + 1;
            Q.push({nz,nx,ny});
        }
    }

    int maxday = 0;

    for(int l = 0; l < h; l++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dist[l][i][j] == -1){
                    cout << -1;
                    return 0;
                }
                maxday = max(maxday, dist[l][i][j]);
            }
        }
    }
    cout << maxday;
}
