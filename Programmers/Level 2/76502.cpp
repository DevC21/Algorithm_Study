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
        // ������ ���ڸ� xĭ ��ŭ ȸ����Ű�� �ð��� �����ɸ��Ƿ� (�ѹ��� O(n)�� �ð��� �ɸ�)
        // ������ ������(pointer)���� �����ؼ� s�� ���̸�ŭ �ݺ�
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
            // s�� ���̸� �Ѿ�� 0���� �ٽ� ����
            pointer %= s_size;
        }

        if(st.empty() && correct)
            answer++;
        cur++;
    }

    return answer;
}