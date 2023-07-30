#include<bits/stdc++.h>
using namespace std;

int D[100'005];

int solution(int n) {
    D[0] = 0;
    D[1] = 1;

    for(int i = 2; i <= n; i++)
        D[i] = (D[i - 1] + D[i - 2]) % 1234567;

    return D[n];
}