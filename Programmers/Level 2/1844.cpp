#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[105][105];
int vis[105][105];
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solution(vector<vector<int> > maps){
    int answer = 0;

    int n = maps.size();
    int m = maps[0].size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            board[i][j] = maps[i][j];

    queue<pair<int, int>> q;
    vis[0][0] = 1;
    q.push({0, 0});

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx > n || ny < 0 || ny > m)
                continue;
            if(vis[nx][ny] > 0 || board[nx][ny] != 1)
                continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    if(vis[n - 1][m - 1] > 0)
        answer = vis[n - 1][m - 1];
    else
        answer = -1;

    return answer;
}

vector<vector<int> > maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};

int main(){
    int ans = solution(maps);
    return 0;
}