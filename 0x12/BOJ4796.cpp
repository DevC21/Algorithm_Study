#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L = 1, P = 1, V = 1, i = 1, ans;

    while(true){
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0)
            break;
        ans = (V / P * L) + min(V % P, L);

        cout << "Case " << i << ": " << ans << '\n';
        i++;
    }
}