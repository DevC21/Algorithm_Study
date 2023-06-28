#include<bits/stdc++.h>
using namespace std;

int n, m, ans = 1;
int D[41];
vector<int> vip;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        vip.push_back(num);
    }

    D[0] = 1; // 모든 좌석이 VIP일때
    D[1] = 1;
    D[2] = 2;

    for(int i = 3; i <= n; i++){
        D[i] = D[i - 1] + D[i - 2];
    }

    int pre = 0;
    for(auto x : vip){
        ans *= D[x - pre - 1];
        pre = x;
    }
    ans *= D[n - pre];

    cout << ans;
}