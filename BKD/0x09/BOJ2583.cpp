#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int vis[102][102];
int area[102];
int paintcount;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;

    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2 ; j++){
            for(int l = x1 ; l < x2; l++){
                board[j][l] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] || board[i][j] != 0 )
                continue;

            
            queue<pair<int,int> > Q;
            vis[i][j] = 1; // (i, j)을 방문했다고 명시
            Q.push({i, j}); // 큐에 시작점인 (i, j)을 삽입.
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                area[paintcount]++;
                for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue; // 범위 밖일 경우 넘어감
                    if(vis[nx][ny] || board[nx][ny] != 0) 
                        continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                    vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                    Q.push({nx,ny});
                }
            }
            paintcount++;
        }
    }

    cout << paintcount << '\n';
    sort(area, area+paintcount);
    for(int i = 0; i < paintcount; i++){
        cout << area[i] << ' ';
    } 
}