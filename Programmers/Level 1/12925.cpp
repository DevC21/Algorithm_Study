#include<bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;

    if(s[1] == '+')
        answer = stoi(s.substr(1, s.size() - 1));
    else if(s[1] == '-')
        answer = stoi(s.substr(1, s.size() - 1)) * -1;
    else
        answer = stoi(s);

    return answer;
}