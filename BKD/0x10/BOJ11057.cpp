#include<bits/stdc++.h>
using namespace std;
#define mod 10007

int n, ans;
// ���� i�� j�� ������ ������ ���� ����
int D[1005][10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // ���� 1�� ������ ���� �� 1���̴�
    for(int i = 0; i <= 9; i++)
        D[1][i] = 1;

    // ���� i�� 0���� ������ ������ ���� ��� 1���̴�
    for(int i = 0; i <= 1000; i++)
        D[i][0] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 9; j++){
            for(int k = 0; k <= j; k++){
                // D[i][j] = D[i - 1][0] + D[i - 1][1] + ..... + D[i - 1][j]
                D[i][j] += D[i - 1][k] % mod;
            }
        }
    }

    for(int i = 0; i <= 9; i++){
        ans += D[n][i];
    }
    cout << ans % mod;
}