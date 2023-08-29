#include<bits/stdc++.h>
using namespace std;
#define MAX_length 5

char AEIOU[5] = {'A', 'E', 'I', 'O', 'U'};
int answer;
int idx = -1;

void DFS(int n, string s, const string &word){
    idx++;
    if(s == word)
        answer = idx;

    if(n >= MAX_length)
        return;

    for(int i = 0; i < MAX_length; i++){
        DFS(n + 1, s += AEIOU[i], word);
        s.erase(s.end() - 1);
    }
        
}

int solution(string word) {
    DFS(0, "", word);

    return answer;
}