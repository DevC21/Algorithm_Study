#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a,b;
    ll sub;
    cin >> a >> b;

    if(a < b){
        sub = b - a - 1;
        cout << sub << '\n';
        for(ll i = 0; i < sub; i++){
            cout << a + i + 1<< ' ';
        }
    }else if (a > b){
        sub = a - b - 1;
        cout << sub << '\n';
        for(ll i = 0; i < sub; i++){
            cout << b + i + 1<< ' ';
        }
    }else if (a == b){
        cout << 0;
    }
}