#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 1234567

ll D[2005];

ll solution(int n) {
    D[1] = 1;
    D[2] = 2;

    // 1칸, 2칸을 뛸 수 있으므로
    // D[i - 1] : 1칸 전에서 1칸을 뛰면 i칸에 도착.
    // D[i - 2] : 2칸 전에서 2칸을 뛰면 i칸에 도착.
    // D[i] : 위 두 경우의 수를 더하면 i칸에 도달하는 방법의 수를 알아낼 수 있다.
    for(int i = 3; i <= n; i++)
        D[i] = (D[i - 2] + D[i - 1]) % mod;

    return D[n] % mod;
}