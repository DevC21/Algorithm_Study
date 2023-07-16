#include<bits/stdc++.h>
using namespace std;

long long solution(int a, int b) {
    if(a == b)
        return a;
    long long answer = 0;

    int minN = min(a, b);
    int maxN = max(a, b);

    for(int i = minN; i <= maxN; i++)
        answer += i;

    return answer;
}