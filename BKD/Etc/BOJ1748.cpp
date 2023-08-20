#include<bits/stdc++.h>
using namespace std;

int n, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int minus = 9;
    int digit = 1;
    while(n > 0){
        if(n - minus >= 0)
            ans += (minus * digit);
        else if(n - minus < 0)
            ans += (n * digit);
        n -= minus;
        minus *= 10;
        digit++;
    }

    cout << ans;
}