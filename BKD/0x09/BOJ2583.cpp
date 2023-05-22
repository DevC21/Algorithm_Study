#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int vis[102][102];
int area[102];
int paintcount;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;

    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2 ; j++){
            for(int l = x1 ; l < x2; l++){
                board[j][l] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] || board[i][j] != 0 )
                continue;

            
            queue<pair<int,int> > Q;
            vis[i][j] = 1; // (i, j)�� �湮�ߴٰ� ���
            Q.push({i, j}); // ť�� �������� (i, j)�� ����.
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                area[paintcount]++;
                for(int dir = 0; dir < 4; dir++){ // �����¿� ĭ�� ���캼 ���̴�.
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue; // ���� ���� ��� �Ѿ
                    if(vis[nx][ny] || board[nx][ny] != 0) 
                        continue; // �̹� �湮�� ĭ�̰ų� �Ķ� ĭ�� �ƴ� ���
                    vis[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
                    Q.push({nx,ny});
                }
            }
            paintcount++;
        }
    }

    cout << paintcount << '\n';
    sort(area, area+paintcount);
    for(int i = 0; i < paintcount; i++){
        cout << area[i] << ' ';
    } 
}