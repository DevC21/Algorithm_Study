#include<bits/stdc++.h>
using namespace std;

string s1[10005];
string s2[10005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);



    int num;

    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> s1[i];
        list<char> L = {};
        auto t = L.end();
        for(char c : s1[i]){
            switch(c){
                case '-':
                    if( t != L.begin()){
                        t = L.erase(--t);
                    }
                    break;
                case '>':
                    if( t != L.end()){
                        t++;
                    }
                    break;
                case '<':
                    if( t != L.begin()){
                        t--;
                    }
                    break;
                default:
                    L.insert(t, c);
                    break;
            }   
        }
        for(auto c : L)
            s2[i] += c;
    }

    for(int i = 0; i < num; i++){
        for(auto c : s2[i])
            cout << c;
        cout << '\n';
    }


}