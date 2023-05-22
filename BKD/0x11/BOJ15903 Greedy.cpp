#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[1005];
ll ans;

// 매번 최소인 두 원소를 O(N)에 찾는 그리디 풀이
// 우선순위 큐를 이용해 O(lg N)에 탐색 가능한 풀이가 존재
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    for(int i = 0; i < m; i++){
        ll sum = a[0] + a[1];
        a[0] = sum;
        a[1] = sum;
        sort(a, a+n);
    }

    for(int i = 0; i < n; i++){
        ans += a[i];
    }

    cout << ans;
}