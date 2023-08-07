#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 1234567

ll D[2005];

ll solution(int n) {
    D[1] = 1;
    D[2] = 2;

    // 1ĭ, 2ĭ�� �� �� �����Ƿ�
    // D[i - 1] : 1ĭ ������ 1ĭ�� �ٸ� iĭ�� ����.
    // D[i - 2] : 2ĭ ������ 2ĭ�� �ٸ� iĭ�� ����.
    // D[i] : �� �� ����� ���� ���ϸ� iĭ�� �����ϴ� ����� ���� �˾Ƴ� �� �ִ�.
    for(int i = 3; i <= n; i++)
        D[i] = (D[i - 2] + D[i - 1]) % mod;

    return D[n] % mod;
}