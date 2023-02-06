#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int j = 0; j < 2*(n) - 1; j++){
        cout << '*';
    }
    cout << '\n';

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << ' ';
        }
        for(int j = 0; j < 2*(n-i) - 1; j++){
            cout << '*';
        }
        cout << '\n';
    }
    
    for(int i = 2; i < n; i++){
        for(int j = 0; j < n - i; j++){
            cout << ' ';
        }
        for(int j = 0; j < 2*i - 1; j++){
            cout << '*';
        }
        cout << '\n';
    }

    if( n > 1 ){
        for(int j = 0; j < 2*(n) - 1; j++){
            cout << '*';
        }
    }
}