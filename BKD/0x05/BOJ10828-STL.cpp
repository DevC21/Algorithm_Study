#include<bits/stdc++.h>
using namespace std;

int main(void){
    stack<int> S;

    string s;
    int n, x;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "push"){
            cin >> x;
            S.push(x);
        }
        else if(s == "pop"){
            if(!S.empty()){
                x = S.top();
                cout << x << '\n';
                S.pop();
            }
            else{
                cout << -1 << '\n';
            }
        }
        else if(s == "top"){
            if(!S.empty())
                cout << S.top() << '\n';
            else
                cout << -1 << '\n';
        }
        else if(s == "size"){
            cout << S.size() << '\n';
        }
        else if(s == "empty"){
            if(S.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}