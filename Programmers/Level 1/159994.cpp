#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> Q1;
    queue<string> Q2;
    bool chk = true;
    for(auto x : cards1)
        Q1.push(x);
    for(auto x : cards2)
        Q2.push(x);
    for(auto x : goal){
        if(Q1.front() == x) 
            Q1.pop();
        else if(Q2.front() == x) 
            Q2.pop();
        else {
            chk = false;
            break;
        }
    }

    if(chk) answer = "Yes";
    else answer  = "No";

    return answer;
}