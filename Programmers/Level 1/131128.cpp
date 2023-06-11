#include<bits/stdc++.h>
using namespace std;

map<char, int> str1;
map<char, int> str2;

string solution(string X, string Y) {
    string answer = "";

    for(char c : X)
        str1[c - '0']++;
    for(char c : Y)
        str2[c - '0']++;

    for(int i = 9; i >= 0; i--){
        if(str1[i] > 0 && str2[i] > 0){
            int couple = min(str1[i], str2[i]);
            for(int j = 0; j < couple; j++){
                answer += '0' + i;
            }
        }
    }

    if(answer == ""){
        answer = "-1";
    }
    else if(answer[0] == '0'){
        answer = "0";
    }

    return answer;
}