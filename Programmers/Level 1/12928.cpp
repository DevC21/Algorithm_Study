#include<bits/stdc++.h>
using namespace std;

int func(int n){
    int sum = 0;
    for(int i = 1; i * i <= n; i++){
        if(i * i == n){
            sum += i;
            continue;
        }

        if(n % i == 0){
            sum += i;
            sum += (n / i);
        }
    }

    return sum;
}

int solution(int n) {
    return func(n);
}