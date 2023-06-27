#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1'000'000'009

ll D[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t;

    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    for(int i = 4; i < 1000001; i++)
        D[i] = (D[i-1] + D[i-2] + D[i-3]) % MOD;

    while(t--){
        cin >> n;
        cout << D[n] % MOD << '\n';
    }
}