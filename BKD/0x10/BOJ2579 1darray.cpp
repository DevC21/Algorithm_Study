#include<bits/stdc++.h>
using namespace std;

int S[305];
int D[305];
int total;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> S[i];
        total += S[i];
    }

    if(n <= 2){
        cout << total;
        return 0;
    }

    D[1] = S[1];
    D[2] = S[2];
    D[3] = S[3];

    for(int i = 3; i <= n; i++){
        D[i] = min(D[i-2], D[i-3]) + S[i];
    }

    cout << total - min(D[n-1], D[n-2]);
}