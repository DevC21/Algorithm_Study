#include<bits/stdc++.h>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    // ���콺 ������ �̿��� 
    // 1���� n������ ���� n * (n+1) / 2 �� Ǯ ���� ����
    for(int i = 1; i <= count; i++)
        answer += price * i;

    answer -= money;
    if(answer > 0){
        return answer;
    }
    else
        return 0;
}