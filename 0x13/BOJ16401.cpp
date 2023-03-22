#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int m, n;
int a[1000005];

bool solve(ll x){
    if (x == 0)
        return true;

    ll cur = 0;

    for(int i = 0; i < n; i++){
        cur += a[i] / x;
    }

    return cur >= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll st = 0;
    ll en = *max_element(a, a+n);

    while(st < en){
        ll mid = (st + en + 1) / 2;
        if(solve(mid))
            st = mid;
        else
            en = mid-1;
    }

    cout << st;
}