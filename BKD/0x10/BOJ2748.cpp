#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll fibo[91];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    fibo[0] = 0;
    fibo[1] = 1;

    for(int i = 2; i <= 90; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    cout << fibo[n];
}