#include <bits/stdc++.h>
using namespace std;

map<string, int> score;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for(int i = 0; i < name.size(); i++) 
        score[name[i]] = yearning[i];

    for(auto vec : photo){
        int sum = 0;
        for(auto x : vec){
            sum += score[x];
        }
        answer.push_back(sum);
    }

    return answer;
}