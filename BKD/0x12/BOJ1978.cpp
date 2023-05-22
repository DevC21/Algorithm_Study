#include <bits/stdc++.h>
using namespace std;

int cnt;

bool isprime(int n){
    if (n == 1) return 0;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) 
            return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        cnt += isprime(x);
    }

    cout << cnt;
}