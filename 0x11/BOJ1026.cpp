#include<bits/stdc++.h>
using namespace std;

int A[51];
int B[51];
int S;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    sort(A, A+n);
    sort(B, B+n);

    for(int i = 0; i < n; i++){
        S += A[i] * B[n-i-1];
    }

    cout << S;
}