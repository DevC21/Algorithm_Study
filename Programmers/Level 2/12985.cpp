#include<bits/stdc++.h>
using namespace std;

int solution(int n, int a, int b){
    int answer = 1;

    while(true){
        if(a % 2 == 0){
            if(a - 1 == b)
                break;
        }
        else if(a % 2 != 0){
            if(a + 1 == b)
                break;
        }

        if(b % 2 == 0){
            if(b - 1 == a)
                break;
        }
        else if(b % 2 != 0){
            if(b + 1 == a)
                break;
        }

        if(a % 2 == 0) a /= 2;
        else if(a % 2 != 0) a = a / 2 + 1;
        if(b % 2 == 0) b /= 2;
        else if(b % 2 != 0) b = b / 2 + 1;

        answer++;
    }

    return answer;
}