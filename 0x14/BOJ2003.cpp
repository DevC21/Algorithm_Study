#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[10005];
int n;
ll m;
ll ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll tot = a[0];
    int en = 0;

    for(int st = 0; st < n; st++){
        while(en < n && tot < m){
            en++;
            if(en != n) 
                tot += a[en];
        }
        if(en == n) 
            break; // en이 범위를 벗어날시 종료
        if(tot == m)
            ans++;
        tot -= a[st];
    }
    
    cout << ans;
}