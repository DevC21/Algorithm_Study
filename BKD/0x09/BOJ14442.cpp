#include<bits/stdc++.h>
using namespace std;
#define X get<0>
#define Y get<1>
#define Z get<2>

int n, m, k, ans = -1;
bool found = false;
int board[1005][1005];
int dist[1005][1005][11];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            fill(dist[i][j], dist[i][j]+k+1, -1);
 
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

    queue<tuple<int, int, int>> Q;
    for(int i = 0; i <= k; i++)
        dist[0][0][i] = 1;
    Q.push({0, 0, 0});
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();

        // 처음과 끝이 같을 때
        if(X(cur) == n - 1 && Y(cur) == m - 1){
            cout << dist[X(cur)][Y(cur)][Z(cur)];
            found = true;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = X(cur) + dx[i];
            int ny = Y(cur)+ dy[i];
            int nz = Z(cur);
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny][nz] >= 0) continue;

            // 끝에 도달했을 때
            if(nx == n-1 && ny == m-1){
                cout << dist[X(cur)][Y(cur)][Z(cur)] + 1;
                found = true;
                break;
            }

            // 벽이 없을 때 이동
            if(board[nx][ny] == 0){
                dist[nx][ny][nz] = dist[X(cur)][Y(cur)][Z(cur)] + 1;
                Q.push({nx, ny, nz});
            }

            // 벽을 부수고 이동해야 할 때
            if(board[nx][ny] != 0 && nz < k){
                if(dist[nx][ny][nz + 1] >= 0) continue;
				dist[nx][ny][nz + 1] = dist[X(cur)][Y(cur)][Z(cur)] + 1;
				Q.push({nx, ny, nz + 1});
            }
            else if(board[nx][ny] != 0 && nz >= k) continue;

        }
        if(found)
            break;
    }

    if(!found)
        cout << -1;
}