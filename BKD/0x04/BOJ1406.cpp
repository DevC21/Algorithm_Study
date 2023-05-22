#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> L = {};

    string s;

    int m;

    char cmd, input;

    cin >> s;

    cin >> m; 

    for(char c : s)
        L.push_back(c);

    auto t = L.end();


    for(int i = 0; i < m; i++){
        cin >> cmd;
        switch(cmd){
            case 'B':
                if( t != L.begin()){
                    t = L.erase(--t);
                }
                break;
            case 'D':
                if( t != L.end()){
                    t++;
                }
                break;
            case 'L':
                if( t != L.begin()){
                    t--;
                }
                break;
            case 'P':
                cin >> input;
                L.insert(t, input);
                break;
        }
    }

    for(auto c : L)
        cout << c;
}