#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(int num) {
    int answer = 0;

    ll number = num;
    while(number != 1){
        if(number % 2 == 0)
            number /= 2;
        else
            number = number * 3 + 1;
        answer++;
        if(answer >= 500)
            return -1;
    }

    return answer;
}