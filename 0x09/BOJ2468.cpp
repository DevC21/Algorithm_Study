#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
int areacount;
int maxArea;
int maxheight;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] > maxheight)
                maxheight = board[i][j];
        }
    }

    for(int rain = 0; rain <= maxheight; rain++){
        areacount = 0;
        for(int idx = 0; idx < n; idx++){
            fill(vis[idx], vis[idx]+n, 0);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] || board[i][j] <= rain)
                    continue;

                queue<pair<int,int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if(vis[nx][ny] || board[nx][ny] <= rain)
                            continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                areacount++;
            }
        }
        if(areacount > maxArea){
            maxArea = areacount;
        }
    }

    cout << maxArea;

}