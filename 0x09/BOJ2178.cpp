#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
int board[502][502];
int dist[502][502]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
int n , m; // n = ���� ��, m = ���� ��
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // �����¿� �� ������ �ǹ�
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
    dist[0][0] = 0; // (0, 0)�� �湮�ߴٰ� ���
    Q.push({0, 0}); // ť�� �������� (0, 0)�� ����.
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ // �����¿� ĭ�� ���캼 ���̴�.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue; // ���� ���� ��� �Ѿ
            if(dist[nx][ny] >= 0 || board[nx][ny] != 1) 
                continue; // �̹� �湮�� ĭ�̰ų� �Ķ� ĭ�� �ƴ� ���
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // (nx, ny)�� �湮�ߴٰ� ���
            Q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1] + 1; 
}
