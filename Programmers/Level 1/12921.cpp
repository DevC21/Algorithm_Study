#include<bits/stdc++.h>
using namespace std;

vector<int> state(1000000+1, true);

void sieve(int n){
    state[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(!state[i]) continue;
        for(int j = i*i; j <= n; j += i)
            state[j] = false;
    }
}

int solution(int n) {
    int answer = 0;

    sieve(n);

    for(int i = 2; i <= n; i++){
        if(state[i])
            answer++;
    }

    return answer;
}