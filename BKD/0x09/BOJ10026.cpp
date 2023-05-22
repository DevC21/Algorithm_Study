#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
int board[102][102];
int vis[102][102]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
int n , m; // n = ���� ��, m = ���� ��
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // �����¿� �� ������ �ǹ�
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;
    
    cin >> n;
    
    string s;

    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == 'R')
                board[i][j] = 0;
            else if(s[j] == 'G')
                board[i][j] = 1;
            else if(s[j] == 'B')
                board[i][j] = 2;
        }
        m = s.length();
    }

    for(int a = 0; a < 3; a++){
        for(int i = 0; i < n; i++){
            fill(vis[i], vis[i]+m, 0);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] || board[i][j] != a )
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
                        if(vis[nx][ny] || board[nx][ny] != a) 
                            continue; 
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                count++;
            }
        }
    }

    cout << count << ' ';

    count = 0;

    for(int i = 0; i < n; i++){
        fill(vis[i], vis[i]+m, 0);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] || board[i][j] == 2 )
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
                    if(vis[nx][ny] || board[nx][ny] == 2) 
                        continue; 
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            count++;
        }
    }

    for(int i = 0; i < n; i++){
        fill(vis[i], vis[i]+m, 0);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] || board[i][j] != 2 )
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
                    if(vis[nx][ny] || board[nx][ny] != 2) 
                        continue; 
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            count++;
        }
    }

    cout << count;

}
