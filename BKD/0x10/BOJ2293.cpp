#include<bits/stdc++.h>
using namespace std;

int D[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    int coin[n+1];

    for(int i = 1; i <= n; i++){
        cin >> coin[i];
    }

    D[0] = 1;

    for (int i = 1; i <= n; i++){
        for (int j = coin[i]; j <= k; j++)
        {
            D[j] = D[j] + D[j - coin[i]];
        }
    }

    cout << D[k] << '\n';
}