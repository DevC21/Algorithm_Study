#include<bits/stdc++.h>
using namespace std;

int n;
int D[21][21];
bool road[21][21];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
        fill(road[i]+1, road[i]+n+1, true);

    // �־����� ���� �̹� �÷��̵� �ͼ��� ����� �ִܰŸ� ��
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> D[i][j];

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if (i == k || j == k) continue;
                // ���� D[i][j]�� D[i][k] + D[k][j] ���� ũ�ٸ� �ִ� �Ÿ� ���� �ƴϹǷ�
                // �Ұ����� ����̹Ƿ� -1�� ����ϰ� ���� 
                if(D[i][j] > D[i][k] + D[k][j]){
                    cout << "-1\n";
                    return 0;
                }
                // i ? j���� �̵��ð� D[i][j]�� 
                // i ? k, k ? j������ �̵��ð��� �հ� ���ٸ� 
                // i ? k ? j�� ���ļ� ���� ����̹Ƿ� 
                // i ? j�� ���ο� �������� �ʴ´�. 
                // ���� road[i][j]�� false�� �ٲپ� ans�� ������ �ʰ� �Ѵ�.
                if(D[i][j] == D[i][k] + D[k][j]){
                    road[i][j] = false;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(road[i][j])
                ans += D[i][j];
        }
    }

    cout << ans / 2 << '\n';
}