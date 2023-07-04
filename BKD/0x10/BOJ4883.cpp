#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int graph[100005][3];
ll D[100005][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t = 1;
    while(true){
        cin >> n;
        if(n == 0)
            break;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                cin >> graph[i][j];
            }
        }

        D[0][1] = graph[0][1];
        D[0][2] = D[0][1] + graph[0][2];

        D[1][0] = D[0][1] + graph[1][0];
        D[1][1] = min({D[0][1] , D[0][2], D[1][0]}) + graph[1][1];
        D[1][2] = min({D[0][1] , D[0][2], D[1][1]}) + graph[1][2];

        // ������ ��뿡 ������ ��� �� �� �ִ�. (����� ������ 1,000,000���� �۴�.)
        // �� ���� ������ ������ �� ���� ����� �� �� �ֱ⶧���� ��� ����� ���� ����ؾ��Ѵ�
        for(int i = 2; i < n; i++){
            D[i][0] = min({D[i - 1][0], D[i - 1][1], D[i - 1][0] + graph[i - 1][1]}) + graph[i][0];
            D[i][1] = min({D[i - 1][0], D[i - 1][1], D[i - 1][2], D[i][0], D[i - 1][0] + graph[i - 1][1], D[i - 1][1] + graph[i - 1][2]}) + graph[i][1];
            D[i][2] = min({D[i - 1][1], D[i - 1][2], D[i][1], D[i - 1][1] + graph[i - 1][2]}) + graph[i][2];
        }

        cout << t++ << ". " << D[n - 1][1] << '\n';
    }
}