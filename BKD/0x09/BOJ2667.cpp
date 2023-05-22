#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[52][52];
int vis[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
int house[400];
int housecount;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '0')
                board[i][j] = 0;
            else if(s[j] == '1')
                board[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] || board[i][j] != 1)
                continue;

            queue<pair<int,int>> Q;
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                house[housecount]++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if(vis[nx][ny] || board[nx][ny] != 1)
                        continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            housecount++;
        }
    }
    
    cout << housecount << '\n';
    sort(house, house+housecount);
    for(int i = 0; i < housecount; i++){
        cout << house[i] << '\n';
    }

}