#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll n){
    for(ll i = 0; i * i <= n; i++){
        if(i * i == n)
            return i;
    }
    return -1;
}

ll solution(ll n) {
    ll answer = 0;

    ll sqrt = func(n);
    if(sqrt == -1)
        answer = -1;
    else
        answer = (sqrt + 1) * (sqrt + 1);

    return answer;
}