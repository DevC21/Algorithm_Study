#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, areacnt = 1, ans = INT32_MAX;
int mapInfo[101][101];
int vis[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void LandLabel(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] || mapInfo[i][j] <= 0){
                continue;
            }

            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            mapInfo[i][j] = areacnt;
            Q.push({i,j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] || mapInfo[nx][ny] == 0) continue;
                    vis[nx][ny] = 1;
                    mapInfo[nx][ny] = areacnt;
                    Q.push({nx,ny});
                }
            }
            areacnt++;
        }
    }
}

int BFS(int label){
    int len = 0;
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mapInfo[i][j] == label){
                vis[i][j] = 1;
                Q.push({i, j});
            }
        }
    }

    while(!Q.empty()){
        int curSize = Q.size();
        for(int i = 0; i < curSize; i++){
            auto cur = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if(mapInfo[nx][ny] != 0 && mapInfo[nx][ny] != label)
                    return len;
                else if(vis[nx][ny] != 1 && mapInfo[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
        len++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mapInfo[i][j];
        }
    }

    LandLabel();

    for(int i = 1; i < areacnt; i++){
        for(int idx = 0; idx < n; idx++)
            fill(vis[idx], vis[idx]+n, 0);
        ans = min(ans, BFS(i));
    }

    cout << ans;
}