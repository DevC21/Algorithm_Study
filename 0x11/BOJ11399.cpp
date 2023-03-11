#include<bits/stdc++.h>
using namespace std;

int P[1005];
int t;
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> P[i];
    }

    sort(P, P+n);

    for(int i = 0; i < n; i++){
        t = t + P[i];
        ans += t;
    }

    cout << ans;
}