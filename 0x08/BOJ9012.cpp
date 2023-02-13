#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int count = 0;

    string s;

    cin >> n;

    for(int i = 0 ; i < n; i++){
        stack<char> cs;
        bool errorflag = false;
        cin >> s;
        

        for(char c : s){
            if(c == '('){
                cs.push(c);
            }
            
            if (!cs.empty()){
                if(cs.top() == '(' && c == ')'){
                    cs.pop();
                }
                else if(c == ')'){
                    errorflag = true;
                    break;
                }
            }
            else{
                if(c == ')')
                    errorflag = true;
                    break;
            }
        }

        if(cs.empty() && !errorflag)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}