#include<bits/stdc++.h>
using namespace std;

stack<char> st;

bool solution(string s){
    bool answer = true;

    for(auto x : s){
        if(x == '(')
            st.push('(');
        
        // '(' ���� ')'�� ���� ��� ����
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