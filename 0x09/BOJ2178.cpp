#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502];
int dist[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n , m; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    string s;


    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n; i++){
        fill(dist[i], dist[i]+m, -1);
    }

    queue<pair<int,int> > Q;
    dist[0][0] = 0; // (0, 0)을 방문했다고 명시
    Q.push({0, 0}); // 큐에 시작점인 (0, 0)을 삽입.
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue; // 범위 밖일 경우 넘어감
            if(dist[nx][ny] >= 0 || board[nx][ny] != 1) 
                continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // (nx, ny)를 방문했다고 명시
            Q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1] + 1; 
}
