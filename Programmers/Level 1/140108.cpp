#include<bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    int cntcur = 0;
    int cntother = 0;
    char cur = 0;
    for(auto x : s){
        if(cur == 0)
            cur = x;
        if(cur == x)
            cntcur++;
        else{
            cntother++;
        }

        if(cntcur == cntother){
            answer++;
            cntcur = 0;
            cntother = 0;
            cur = 0;
        }
    }
    if(cur != 0)
        answer++;

    return answer;
}