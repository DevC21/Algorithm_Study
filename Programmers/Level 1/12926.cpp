#include<bits/stdc++.h>
using namespace std;

string solution(string s, int n) {
    string answer = "";

    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ')
            continue;

        if(s[i] >= 'a' && s[i] <= 'z' ){
            if(s[i] + n > 'z')
                s[i] = s[i] - 'z' + n + 'a' - 1;
            else
                s[i] += n;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            if(s[i] + n > 'Z')
                s[i] = s[i] - 'Z' + n + 'A' - 1;
            else
                s[i] += n;
        }
    }

    answer = s;
    return answer;
}