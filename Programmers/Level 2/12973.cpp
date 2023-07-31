#include<bits/stdc++.h>
using namespace std;

stack<char> st;

int solution(string s){
    int answer = 0;

    for(auto x : s){
        if(!st.empty()){
            if(x == st.top())
                st.pop();
            else
                st.push(x);
        }
        else
            st.push(x);
    }

    if(st.empty())
        answer = 1;
    else
        answer = 0;

    return answer;
}