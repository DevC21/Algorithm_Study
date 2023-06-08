#include<bits/stdc++.h>
using namespace std;

int a = 3, b = 1, n = 20;

int solution(int a, int b, int n) {
    int answer = 0;

    while(n >= a){
        answer += (n / a) * b;
        n = (n / a) * b + (n % a);
    }

    return answer;
}

int main(){
    int ans = solution(a, b, n);

    return 0;
}