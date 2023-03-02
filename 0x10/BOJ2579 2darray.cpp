#include<bits/stdc++.h>
using namespace std;

int S[305];
int D[305][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> S[i];
    }

    if(n == 1){
        cout << S[1];
        return 0;
    }

    D[1][1] = S[1];
    D[1][2] = 0;
    D[2][1] = S[2];
    D[2][2] = S[1] + S[2];


    for(int i = 3; i <= n; i++){
        D[i][1] = max(D[i-2][1], D[i-2][2]) + S[i];
        D[i][2] = D[i-1][1] + S[i];
    }

    cout << max(D[n][1], D[n][2]);
}