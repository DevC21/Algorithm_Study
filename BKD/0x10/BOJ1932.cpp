#include<bits/stdc++.h>
using namespace std;

int arr[501][501];
int D[501][501];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j]; 
        }
    }

    D[1][1] = arr[1][1];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            D[i][j] = max(D[i-1][j-1], D[i-1][j]) + arr[i][j];
        }
    }

    int maxval = 0;

    for(int i = 1; i <= n; i++){
        if(maxval < D[n][i])
            maxval = D[n][i];
    }

    cout << maxval;
}