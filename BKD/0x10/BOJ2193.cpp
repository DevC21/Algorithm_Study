#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 길이 i의 수열은 맨 끝이 0이거나 1이다.
// 0인 수열은 나머지 자리를 채우는 경우의 수인 f(i - 1)개가 있다.
// 1인 수열은 뒤에서 두 번째 수가 0이 되어야 하므로 숫자 2개가 고정되어 f(i - 2)개가 있다.
// 따라서 f(i) = f(i - 1) + f(i - 2)가 성립하며 피보나치 수열이다.

int n;
ll D[91];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[1] = 1;
    D[2] = 1;

    for(int i = 3; i <= n; i++)
        D[i] = D[i - 1] + D[i - 2];

    cout << D[n];
}