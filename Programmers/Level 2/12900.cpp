#include<bits/stdc++.h>
using namespace std;
#define div 1'000'000'007

int D[60'005];

int solution(int n) {
    int answer = 0;
    
    D[1] = 1;
    D[2] = 2;

    for(int i = 3; i <= n; i++)
        D[i] = (D[i - 1] + D[i - 2]) % div;

    answer = D[n] % div;

    return answer;
}