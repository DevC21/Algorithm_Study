#include<bits/stdc++.h>
using namespace std;

map<char, bool> chk;

string solution(string s, string skip, int index) {
    string answer = "";
    for(auto x : skip)
        chk[x] = true;

    for(auto x : s){
        char c = x;
        
        for(int i = 0; i < index; i++){
            c++;
            if(c > 'z')
                c = 'a';
            if(chk[c])
                i--;
        }
        answer += c;
    }

    return answer;
}