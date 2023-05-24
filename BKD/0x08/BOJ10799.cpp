#include<bits/stdc++.h>
using namespace std;

stack<char> s;
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    char pre;
    for(auto x : str){
        if(x == '(')
            s.push(x);
        

        if(x == ')'){
            // 이전에 나온 문자가 '(' 라면 레이저이므로
            // 스택에 있는 '(' 개수만큼의 쇠파이프를 자르게 된다
            // 따라서 ans에 스택의 크기만큼 더해준다.
            if(pre == '('){
                s.pop();
                ans += s.size();
            }
            // 이전에 나온 문자가 ')' 라면 쇠파이프의 끝이므로
            // 쇠파이프를 자를때 세지않은 쇠파이프의 끝 부분을 센다.
            // 따라서 ans에 1만큼 더해준다.
            else if(pre == ')'){
                s.pop();
                ans++;
            }
        }
        pre = x;
    }

    cout << ans;
}