#include<bits/stdc++.h>
using namespace std;

int D[1005][1005];
int mod = 10007;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 1000; i++){
        D[i][0] = D[i][i] = 1;
        for(int j = 1; j < i; j++){
            D[i][j] = (D[i-1][j] + D[i-1][j-1])%mod;
        }
    }

    int n, k;
    cin >> n >> k;
    cout << D[n][k];
}