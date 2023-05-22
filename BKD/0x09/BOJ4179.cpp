#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[1002][1002];
int distJ[1002][1002];
int distF[1002][1002]; // 해당 칸을 방문했는지 여부를 저장
int n , m; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int,int> > JQ;
    queue<pair<int,int> > FQ;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        fill(distJ[i], distJ[i]+m, -1);
        fill(distF[i], distF[i]+m, -1);
    }


    
    string s;

    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '#'){
                board[i][j] = -1;
            }
            else if(s[j] == 'J'){
                JQ.push({i, j});
                distJ[i][j] = 0;
            }
            else if(s[j] == 'F'){
                FQ.push({i, j});
                distF[i][j] = 0;
            }
        }
    }

    while(!FQ.empty()){
        pair<int,int> cur = FQ.front(); FQ.pop();
        for(int dir = 0; dir < 4; dir++){ 
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; 
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue; 
            if(distF[nx][ny] >= 0 || board[nx][ny] < 0) 
                continue; 
            distF[nx][ny] = distF[cur.X][cur.Y] + 1; 
            FQ.push({nx,ny});
        }
    }
    
    while(!JQ.empty()){
        pair<int,int> cur = JQ.front(); JQ.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << distJ[cur.X][cur.Y] + 1;
                return 0;
            }
            if(distJ[nx][ny] >= 0 || board[nx][ny] < 0) 
                continue; // 이미 방문한 칸이거나 벽일 경우
            if(distF[nx][ny] != -1 && distJ[cur.X][cur.Y] + 1 >= distF[nx][ny])
                continue; // 불이 전파된 칸일 경우
            distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
            JQ.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE";
}