#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 1'000'000'009
int n, t;
int D[100'005][4];
ll ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;


    // n이 1, 2, 3일때 각각 1, 2, 3으로 끝나는 경우의 수
    D[1][1] = 1;
    D[2][1] = 0;
    D[2][2] = 1;
    D[3][1] = 1;
    D[3][2] = 1;
    D[3][3] = 1;

    for(int i = 4; i <= 100'000; i++){
        // i 가 6일때
        // 5에서 2와 3으로 끝나는 경우의 수에 1을 더하면 6이므로 두 경우의 수를 더한다.
        D[i][1] = (D[i - 1][2] + D[i - 1][3]) % mod;
        // 4에서 1과 3으로 끝나는 경우의 수에 2를 더하면 6이므로 두 경우의 수를 더한다.
        D[i][2] = (D[i - 2][1] + D[i - 2][3]) % mod;
        // 3에서 1과 2로 끝나는 경우의 수에 3을 더하면 6이므로 두 경우의 수를 더한다.
        D[i][3] = (D[i - 3][1] + D[i - 3][2]) % mod;
    }

    while(t--){
        cin >> n;

        ans = 0;
        for(int i = 1; i <= 3; i++)
            ans += D[n][i] % mod;

        cout << ans % mod << '\n';
    }

}