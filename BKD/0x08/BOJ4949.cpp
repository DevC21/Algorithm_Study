#include<bits/stdc++.h>
using namespace std;

bool errorflag;

int main(){
    string s;



    while( !(s.compare(".") == 0)){
        stack<char> cs;
        errorflag = false;

        getline(cin, s);


        for(char c : s){
            if(c == '[' || c == '('){
                cs.push(c);
            }
            
            if (!cs.empty()){
                if(cs.top() == '[' && c == ']'){
                    cs.pop();
                }            
                else if(cs.top() == '(' && c == ')'){
                    cs.pop();
                }
                else if(c == ']' || c == ')'){
                    errorflag = true;
                    break;
                }
            }
            else{
                if(c == ']' || c == ')')
                    errorflag = true;
                    break;
            }
        }

        if( (!(s.compare(".") == 0)) && !errorflag){
            if(cs.empty()){
                cout << "yes" << '\n';
            }
            else{
                cout << "no" << '\n';
            }
        }
        else if(errorflag){
                cout << "no" << '\n';
        }
    }
}