#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[301][301];
int tmp[301][301];
int vis[301][301];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int year;
int areacnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    while(true){
        areacnt = 0;
        for(int idx = 0; idx < n; idx++){
            fill(vis[idx], vis[idx]+m, 0);
            fill(tmp[idx], tmp[idx]+m, 0);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] || board[i][j] <= 0){
                    continue;
                }

                queue<pair<int, int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()){
                    int sea = 0;
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny]) continue;
                        if(board[nx][ny] <= 0){
                            sea++;
                            continue;
                        }
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                    tmp[cur.X][cur.Y] = board[cur.X][cur.Y] - sea;
                }
                areacnt++;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = tmp[i][j];

        if(areacnt == 0){
            cout << 0;
            return 0;
        }
        else if(areacnt >= 2){
            cout << year;
            return 0;
        }
        year++;
    }
}