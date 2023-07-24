#include<bits/stdc++.h>
using namespace std;

stack<char> st;

bool solution(string s){
    bool answer = true;

    for(auto x : s){
        if(x == '(')
            st.push('(');
        
        // '(' 보다 ')'가 많은 경우 검출
        if(st.empty())
            if(x == ')')
                return false;

        if(!st.empty())
            if(x == ')')
                st.pop();
    }

    if(!st.empty())
        answer = false;

    return answer;
}