#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// ��� ó���ܿ��� % 1000000000�� �������

ll D[101][10];
ll ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= 9; i++)
        D[1][i] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            if(j == 0)
                D[i][j] = D[i - 1][1] % 1000000000;
            else if(j == 9)
                D[i][j] = D[i - 1][8] % 1000000000;
            else
                D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % 1000000000;
        }
    }

    for(int i = 0; i <= 9; i++){
        ans += (D[n][i] % 1000000000);
    }

    cout << ans % 1000000000;
}