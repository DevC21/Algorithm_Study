#include<bits/stdc++.h>
using namespace std;

stack<char> st;
bool correct;

int solution(string s) {
    int answer = 0;

    int cur = 0;
    int s_size = s.size();
    while(true){
        if(cur >= s_size)
            break;
        stack<char> st;
        correct = true;
        // 실제로 문자를 x칸 만큼 회전시키면 시간이 오래걸리므로 (한번당 O(n)의 시간이 걸림)
        // 가상의 포인터(pointer)에서 시작해서 s의 길이만큼 반복
        int pointer = cur;
        for(int i = 0; i < s_size; i++){
            if(s[pointer] == '[' || s[pointer] == '(' || s[pointer] == '{')
                st.push(s[pointer]);
            
            if(st.empty()){
                if(s[pointer] == ']' || s[pointer] == ')' || s[pointer] == '}'){
                    correct = false;
                    break;
                }
            }
            else if(!st.empty()){
                if(st.top() == '[' && s[pointer] == ']')
                    st.pop();
                else if(st.top() == '(' && s[pointer] == ')')
                    st.pop();
                else if(st.top() == '{' && s[pointer] == '}')
                    st.pop();
            }

            pointer++;
            // s의 길이를 넘어가면 0부터 다시 시작
            pointer %= s_size;
        }

        if(st.empty() && correct)
            answer++;
        cur++;
    }

    return answer;
}