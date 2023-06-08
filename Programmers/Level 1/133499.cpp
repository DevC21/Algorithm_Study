#include<bits/stdc++.h>
using namespace std;

string dup[4] = {"ayaaya", "yeye", "woowoo", "mama"};
string arr[4] = {"aya", "ye", "woo", "ma"};

int solution(vector<string> babbling) {
    int answer = 0;

    for (string s : babbling) {
            for(int i = 0; i < 4; i++)
                s =  regex_replace(s, regex(dup[i]), "  " );

            for(int i = 0; i < 4; i++)
                s =  regex_replace(s, regex(arr[i]), " " );

            s =  regex_replace(s, regex(" "), "" );
            
            if (strcmp(s.c_str(), "") == 0)
                answer++;
    }
    return answer;
}