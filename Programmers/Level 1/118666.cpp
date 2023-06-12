#include<bits/stdc++.h>
using namespace std;

map<char, int> m;

char RCJA[4] = {'R', 'C', 'J', 'A'};
char TFMN[4] = {'T', 'F', 'M', 'N'};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    for(int i = 0; i < survey.size(); i++){
        if(choices[i] < 4){
            m[survey[i][0]] += 4 - choices[i];
        }
        else if(choices[i] > 4){
            m[survey[i][1]] += choices[i] - 4;
        }
    }

    for(int i = 0; i < 4; i++){
        if(m[RCJA[i]] >= m[TFMN[i]]){
            answer += RCJA[i];
        }
        else if(m[RCJA[i]] < m[TFMN[i]]){
            answer += TFMN[i];
        }
    }

    return answer;
}