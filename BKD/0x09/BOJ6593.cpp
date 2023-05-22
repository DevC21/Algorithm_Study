#include<bits/stdc++.h>
using namespace std;
#define X get<2>
#define Y get<1>
#define Z get<0>

int board[31][31][31];
int dist[31][31][31];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int l, r, c;
int minTime;
bool found;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    l = 1;
    r = 1;
    c = 1;

    while(l != 0 && r != 0 && c != 0){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0)
            break;
        found = false;
        queue<tuple<int,int,int>> Q;
        string s;

        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                fill(board[i][j], board[i][j]+c, 0);
                fill(dist[i][j], dist[i][j]+c, 0);
            }
        }
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                cin >> s;
                for(int k = 0; k < c; k++){
                    if(s[k] == 'S'){
                        Q.push({i,j,k});
                        dist[i][j][k] = 0;
                    }
                    else if(s[k] == '.'){
                        dist[i][j][k] = -1;
                    }
                    else if(s[k] == '#'){
                        board[i][j][k] = 1;
                    }
                    else if(s[k] == 'E'){
                        board[i][j][k] = 2;
                        dist[i][j][k] = -1;
                    }
                }
            }
        }

        while(!Q.empty()){
            tuple<int,int,int> cur = Q.front(); Q.pop();
            if(board[Z(cur)][Y(cur)][X(cur)] == 2){
                    minTime = dist[Z(cur)][Y(cur)][X(cur)];
                    cout << "Escaped in " << minTime << " minute(s)." << '\n';
                    found = true;
                    break;
            }
            for(int dir = 0; dir < 6; dir++){ 
                int nx = X(cur) + dx[dir];
                int ny = Y(cur) + dy[dir]; 
                int nz = Z(cur) + dz[dir]; 
                if(nx < 0 || nx >= c || ny < 0 || ny >= r || nz < 0 || nz >= l)
                    continue; 
                if(dist[nz][ny][nx] >= 0 || board[nz][ny][nx] == 1)
                    continue;
                if(board[nz][ny][nx] == 2){
                    minTime = dist[Z(cur)][Y(cur)][X(cur)] + 1;
                    cout << "Escaped in " << minTime << " minute(s)." << '\n';
                    found = true;
                    break;
                }
                dist[nz][ny][nx] = dist[Z(cur)][Y(cur)][X(cur)] + 1;
                Q.push({nz,ny,nx});
            }
            if(found)
                break;
        }

        if(!found)
            cout << "Trapped!" << '\n';
    }
}