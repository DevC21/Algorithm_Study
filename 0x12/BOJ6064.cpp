#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        int M, N, x, y;
        bool found = false;

        cin >> M >> N >> x >> y;

        if(x == M) 
            x = 0;
        if(y == N)
            y = 0;

        int l = lcm(M, N);

        for(int i = x; i <= l; i += M){
            if(i == 0) continue;
            if(i % N == y){
                cout << i << '\n';
                found = true;
            }
        }
        if(!found)
            cout << -1 << '\n';
    }
}