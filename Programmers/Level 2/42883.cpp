#include<bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    deque<char> dq;

    for(auto x : number){
        if(!dq.empty() && k > 0 && x > dq.back()){
            while(!dq.empty() && dq.back() < x && k > 0 ){
                dq.pop_back();
                k--;
            }
        }
        dq.push_back(x);
    }

    if(k > 0){
        for(int i = 0; i < k; i++)
            dq.pop_back();
    }

    while(!dq.empty()){
        answer += dq.front();
        dq.pop_front();
    }

    return answer;
}