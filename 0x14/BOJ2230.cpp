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

    int st = 0;
    int en = 0;

    while(en < n || st < n){
        if(a[en] - a[st] < m){
            en++;
        }
        else if(a[en] - a[st] >= m){
            ans = min(ans, a[en] - a[st]);
            st++;
        }
    }

    cout << ans;
}