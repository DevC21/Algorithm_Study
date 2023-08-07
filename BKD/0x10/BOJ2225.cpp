#include<bits/stdc++.h>
using namespace std;
#define mod 1'000'000'000

int n, k;
// D[k][n] : k���� 0 ~ n�� ���ڸ� ���� n�� ���� �� �ִ� ����� ��
int D[205][205];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    // n = 0�� ��, D[k][n] = 1�̴�.
    // k���� ���ڸ� ���� 0�� ����� ����� 1�� �ۿ� ����.
    // k = 1�� ��, D[k][n] = 1�̴�.
    // 1���� ���ڸ� ���� n�� ����� ����� 1�� �ۿ� ����.
    D[0][0] = 1;


    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            for(int m = 0; m <= j; m++){
                D[i][j] += D[i - 1][j - m];
                D[i][j] %= mod;
            }
        }
    }

    cout << D[k][n];
}