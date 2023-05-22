#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        queue<pair<int,int>> Q;
        int board[51][51];
        bool vis[51][51];

        int count = 0;

        cin >> m >> n >> k;

        for(int a = 0; a < n; a++){
            fill(board[a], board[a]+m, 0);
            fill(vis[a], vis[a]+m, 0);
        }

        for(int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] || board[i][j] != 1 )
                    continue;

                queue<pair<int,int> > Q;
                vis[i][j] = 1;
                Q.push({i, j}); 
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){ 
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; 
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue; 
                        if(vis[nx][ny] || board[nx][ny] != 1) 
                            continue; 
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                count++;
            }
        }

        cout << count << '\n';
    }
}