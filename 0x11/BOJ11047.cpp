#include<bits/stdc++.h>
using namespace std;

int coin[11];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int ans = 0;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
            cin >> coin[i];
    }

    for(int i = n-1; i >= 0; i--){
        ans += k / coin[i];
        k %= coin[i];
    }

    cout << ans;
}