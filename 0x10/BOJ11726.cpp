#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll D[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    D[1] = 1;
    D[2] = 2;

    if(n == 1){
        cout << 1;
        return 0;
    }
    else if(n == 2){
        cout << 2;
        return 0;
    }

    for(int i = 3; i <=n; i++){
        D[i] = (D[i-2] % 10007) + (D[i-1] % 10007);
    }

    cout << D[n] % 10007;
}