#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define div 1'000'000'007

// Ä«Å»¶û ¼ö Âü°í
// https://ko.wikipedia.org/wiki/%EC%B9%B4%ED%83%88%EB%9E%91_%EC%88%98

int t, l;
ll D[2501];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    D[0] = 1;
    D[1] = 1;

    for(int i = 2; i <= 2500; i++)
        for(int j = 0; j <= i - 1; j++)
            D[i] = (D[i] + D[j] * D[i - 1 - j]) % div; // Ä«Å»¶û ¼ö

    while(t--){
        cin >> l;

        if(l % 2 == 0) 
            cout << D[l / 2] << '\n';
        else
            cout << 0 << '\n';
    }
}