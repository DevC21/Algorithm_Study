#include<bits/stdc++.h>
using namespace std;

stack<char> s;
char pre;
int ans;
int tmp = 1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            s.push(str[i]);
            tmp *= 2;
        }
        else if(str[i] == '['){
            s.push(str[i]);
            tmp *= 3;
        }
        else if(str[i] == ')'){
            // 올바르지 못한 괄호열
            if(s.empty() || s.top() != '('){
                cout << 0;
                return 0;
            }

            if(str[i-1] == '(') ans += tmp;
            s.pop();
            tmp /= 2;
        }
        else{ //str[i] == ']'
            // 올바르지 못한 괄호열
            if(s.empty() || s.top() != '['){
                cout << 0;
                return 0;
            }
            
            if(str[i-1] == '[') ans += tmp;
            s.pop();
            tmp /= 3;
        }
    }

    if(s.empty()) cout << ans;
    else cout << 0;
}