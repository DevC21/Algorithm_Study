#include<bits/stdc++.h>
using namespace std;

int t, a, b;

int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    while(t--){
        cin >> a >> b;

        cout << lcm(a , b) << '\n';
    }
}