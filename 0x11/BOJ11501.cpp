#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll p[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while(t-- > 0){
        ll max = 0;
        ll ans = 0;
        int n = 0;

        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> p[i];
        }

        for(int i = n-1; i >= 0; i--){
            if(max < p[i])
                max = p[i];
            else
                ans += (max - p[i]);
        }

        cout << ans << '\n';
    }
}