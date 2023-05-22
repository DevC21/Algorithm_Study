#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll D[105] = {0, 1, 1, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for(int i = 4; i <= 100; i++){
        D[i] = D[i-2] + D[i-3];
    }

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        cout << D[n] << '\n';
    }
}