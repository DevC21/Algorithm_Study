#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int n, x;

    string s;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "push"){
            cin >> x;
            Q.push(x);
        }
        else if(s == "pop"){
            if(Q.empty())
                cout << -1 << '\n';
            else{
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if(s == "size"){
            cout << Q.size() << '\n';
        }
        else if(s == "empty"){
            if(Q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(s == "front"){
            if(Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.front() << '\n';
        }
        else if(s == "back"){
            if(Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.back() << '\n';
        }

    }
}