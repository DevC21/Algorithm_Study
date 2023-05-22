#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
int board[1002][1002];
int distJ[1002][1002];
int distF[1002][1002]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
int n , m; // n = ���� ��, m = ���� ��
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // �����¿� �� ������ �ǹ�
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
            int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << distJ[cur.X][cur.Y] + 1;
                return 0;
            }
            if(distJ[nx][ny] >= 0 || board[nx][ny] < 0) 
                continue; // �̹� �湮�� ĭ�̰ų� ���� ���
            if(distF[nx][ny] != -1 && distJ[cur.X][cur.Y] + 1 >= distF[nx][ny])
                continue; // ���� ���ĵ� ĭ�� ���
            distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
            JQ.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE";
}