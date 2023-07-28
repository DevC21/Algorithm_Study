#include<bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i = 1; i <= n; i++){
        int sum = i;
        if(sum == n)
            answer++;
        for(int j = i + 1; j <= n; j++){
            sum += j;
            if(sum > n)
                break;
            if(sum == n)
                answer++;
        }
    }

    return answer;
}