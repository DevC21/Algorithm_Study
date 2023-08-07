#include<bits/stdc++.h>
using namespace std;
#define mod 1'000'000'000

int n, k;
// D[k][n] : k개의 0 ~ n의 숫자를 더해 n을 만들 수 있는 경우의 수
int D[205][205];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    // n = 0일 때, D[k][n] = 1이다.
    // k개의 숫자를 더해 0을 만드는 방법은 1개 밖에 없다.
    // k = 1일 때, D[k][n] = 1이다.
    // 1개의 숫자를 더해 n을 만드는 방법은 1개 밖에 없다.
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