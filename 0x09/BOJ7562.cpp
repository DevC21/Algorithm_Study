#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
int dist[502][502]; 
int dx[8] = {1,2,1,2,-1,-2,-1,-2};
int dy[8] = {2,1,-2,-1,-2,-1,2,1}; 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        int l, curX, curY;
        int destX, destY;
        bool found = false;

        cin >> l;

        for(int i = 0; i < l; i++){
            fill(dist[i], dist[i]+l, -1);
            fill(board[i], board[i]+l, 0);
        }
        
        cin >> curX >> curY;
        cin >> destX >> destY;

        board[destX][destY] = 1;

        queue<pair<int,int> > Q;
        dist[curX][curY] = 0;
        Q.push({curX, curY});
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            if(board[cur.X][cur.Y] == 1){
                cout << dist[cur.X][cur.Y] << '\n';
                break;
            }
            for(int dir = 0; dir < 8; dir++){ 
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 
                if(nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue; 
                if(dist[nx][ny] >= 0) 
                    continue; 
                if(board[nx][ny] == 1){
                    cout << dist[cur.X][cur.Y] + 1 << '\n';
                    found = true;
                    break;
                }
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
            if(found)
                break;
        }
    }
}
