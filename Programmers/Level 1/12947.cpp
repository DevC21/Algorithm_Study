#include<bits/stdc++.h>
using namespace std;

bool solution(int x) {
    bool answer = false;

    int num = x;
    int div = 0;
    while(num != 0){
        div += num % 10;
        num /= 10;
    }

    if(x % div == 0)
        answer = true;

    return answer;
}