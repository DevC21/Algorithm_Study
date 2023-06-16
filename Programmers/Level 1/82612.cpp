#include<bits/stdc++.h>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    // 가우스 공식을 이용한 
    // 1부터 n까지의 합은 n * (n+1) / 2 로 풀 수도 있음
    for(int i = 1; i <= count; i++)
        answer += price * i;

    answer -= money;
    if(answer > 0){
        return answer;
    }
    else
        return 0;
}