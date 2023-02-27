#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int cnt = 0;
    int mxcnt = 0;
    ll mxval = -(1ll << 62)-1;
    ll tmp = -(1ll << 62)-1;

    for(int i = 0; i < n; i++){
        if(tmp == arr[i]){
            cnt++;
        }
        else if(i == 0 || tmp != arr[i]){
            if(mxcnt < cnt){
                mxcnt = cnt;
                mxval = tmp;
            }
            tmp = arr[i];
            cnt = 1;
        }

        if(i == n-1){
            if(mxcnt < cnt){
                mxcnt = cnt;
                mxval = tmp;
            }
        }
    }

    cout << mxval;
}