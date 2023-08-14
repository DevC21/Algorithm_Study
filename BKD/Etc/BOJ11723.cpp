#include<bits/stdc++.h>
using namespace std;

int m;
map<int, bool> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m;

    while(m--){
        string str;
        int num;
        cin >> str;

        if(str == "add"){
            cin >> num;
            s[num] = true;
        }
        else if(str == "remove"){
            cin >> num;
            s[num] = false;
        }
        else if(str == "check"){
            cin >> num;
            if(s[num])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(str == "toggle"){
            cin >> num;
            if(s[num])
                s[num] = false;
            else
                s[num] = true;
        }
        else if(str == "all"){
            for(int i = 1; i <= 20; i++)
                s[i] = true;
        }
        else if(str == "empty"){
            for(int i = 1; i <= 20; i++)
                s[i] = false;
        }
    }
}

