#include<bits/stdc++.h>
using namespace std;

string solution(string s) {
    if(s[0] >= 'a' && s[0] <= 'z')
        s[0] = s[0] - 'a' + 'A';

    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] == ' ' && s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 'a' + 'A';
        else if(s[i - 1] == ' ' && s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    }

    return s;
}