#include<bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;

    string s;
    while(n > 0){
        s += to_string(n % 3);
        n /= 3;
    }


    int trit = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        answer += trit * (s[i] - '0');
        trit *= 3;
    }
        
    return answer;
}