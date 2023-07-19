#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll width[100005];
ll price[100005];
ll minp = INT32_MAX;
ll totalwidth, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        cin >> width[i];
        totalwidth += width[i];
    }
        

    for(int i = 0; i < n; i++){
        cin >> price[i];
        minp = min(price[i], minp);
    }
        
    if(price[0] == minp){
        cout << price[0] * totalwidth;
        return 0;
    }

    ans += price[0] * width[0];

    ll cur = price[0];
    for(int i = 1; i < n - 1; i++){
        if(price[i] < cur){
            ans += price[i] * width[i];
            cur = price[i];
        }
        else
            ans += cur * width[i];
    }

    cout << ans;
}