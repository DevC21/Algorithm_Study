#include<bits/stdc++.h>
using namespace std;

// 문제는 복잡하지만 간단하게 주어진 숫자를 2진수로 표현했을 때, 1의 숫자를 세는 문제

int solution(int n){
    int ans = 0;
    
    while(n != 0){
        ans += n%2;
        n /=2;
    }

    return ans;
}