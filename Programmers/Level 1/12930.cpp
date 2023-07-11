#include<bits/stdc++.h>
using namespace std;

string solution(string s) {
    int idx = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            idx = 0;
            continue;
        }

        if(idx % 2 == 0){
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 'a' + 'A';
        }
        else{
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
        }
        idx++;
    }

    return s;
}