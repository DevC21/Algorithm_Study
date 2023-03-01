#include<bits/stdc++.h>
using namespace std;

int D[12];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for(int i = 4; i < 12; i++){
        for(int j = i-3; j < i; j++){
            D[i] += D[j]; 
        }
    }

    for(int i = 0; i < t; i++){
        int n;

        cin >> n;

        cout << D[n] << '\n';
    }
}