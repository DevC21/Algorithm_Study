#include<bits/stdc++.h>
using namespace std;

int a[100005];
int ans = 2000000001;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    for(int i = 0; i < n; i++){
        int idx = lower_bound(a, a+n, a[i]+m) - a;
        if(idx != n){
            if(ans > a[idx] - a[i]){
                ans = a[idx] - a[i];
            }
        }
    }

    cout << ans;
}