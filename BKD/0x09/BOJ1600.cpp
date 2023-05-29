#include<bits/stdc++.h>
using namespace std;
#define X get<0>
#define Y get<1>
#define Z get<2>

int k, w, h, ans = -1;
int board[201][201];
int dist[201][201][31];

int dx[] = {1, 2, 1, 2, -1, -2 ,-1, -2, 1, 0, -1, 0};
int dy[] = {2, 1, -2, -1, 2, 1 ,-2, -1, 0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> w >> h;

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> board[i][j];


    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            fill(dist[i][j], dist[i][j]+k+1, -1);
    
    queue<tuple<int, int, int>> Q;
    dist[0][0][0] = 0;
    Q.push({0, 0, 0});
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        if(X(cur) == h - 1 && Y(cur) == w - 1){
            ans = dist[X(cur)][Y(cur)][Z(cur)];
            break;
        }
        for(int i = 0; i < 12; i++){
            int nx = X(cur) + dx[i];
            int ny = Y(cur)+ dy[i];
            int nz = Z(cur);
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(dist[nx][ny][nz] >= 0 || board[nx][ny] != 0) continue;
            if(i < 8){
                if(dist[nx][ny][nz + 1] >= 0) continue;
				if(nz >= k) continue;
				dist[nx][ny][nz + 1] = dist[X(cur)][Y(cur)][Z(cur)] + 1;
				Q.push({nx, ny, nz + 1});
            }
            else{
                dist[nx][ny][nz] = dist[X(cur)][Y(cur)][Z(cur)] + 1;
                Q.push({nx, ny, nz});
            }
        }
    }

    cout << ans;
}