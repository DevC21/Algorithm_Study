#include<bits/stdc++.h>
using namespace std;
#define X get<0>
#define Y get<1>
#define Wallbroken get<2>

int board[1002][1002];
int dist[1002][1002][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;
bool found = false;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<tuple<int,int,int>> Q;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fill(dist[i][j], dist[i][j]+2, -1);
        }
    }

    Q.push({0,0,0});
    dist[0][0][0] = 1;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '0'){
                board[i][j] = 0;
            }
            else if(s[j] == '1'){
                board[i][j] = 1;
            }
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(X(cur) == n-1 && Y(cur) == m-1){
                cout << dist[X(cur)][Y(cur)][Wallbroken(cur)];
                found = true;
                break;
        }
        for(int dir = 0; dir < 4; dir++){
            int nx = X(cur) + dx[dir];
            int ny = Y(cur) + dy[dir];  

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(dist[nx][ny][Wallbroken(cur)] >= 0)
                continue;
            if(nx == n-1 && ny == m-1){
                cout << dist[X(cur)][Y(cur)][Wallbroken(cur)] + 1;
                found = true;
                break;
            }
            if(board[nx][ny] == 0){
                dist[nx][ny][Wallbroken(cur)] = dist[X(cur)][Y(cur)][Wallbroken(cur)] + 1;
                Q.push({nx, ny, Wallbroken(cur)});
            }

            if(board[nx][ny] == 1 && Wallbroken(cur) == 0){
                dist[nx][ny][1] = dist[X(cur)][Y(cur)][Wallbroken(cur)] + 1;
                Q.push({nx, ny, 1});
            }
        }
        if(found)
            break;
    }

    if(!found){
        cout << -1;
    }
}