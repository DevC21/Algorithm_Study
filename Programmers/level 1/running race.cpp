#include <bits/stdc++.h>

using namespace std;

map<string, int> name_stand;
map<int, string> stand_name;

vector<string> solution(vector<string> players, vector<string> callings) {
    int idx = 1;
    for(auto x : players){
        name_stand[x] = idx;
        stand_name[idx] = x;
        idx++;
    }
    
    for(auto x : callings){
        int tmp_i = name_stand[x];
        string tmp_s = stand_name[tmp_i - 1];
        name_stand[x]--;
        stand_name[tmp_i - 1] = x;
        
        name_stand[tmp_s]++;
        stand_name[tmp_i] = tmp_s;
    }
    
    vector<string> answer;
    for(int i = 1; i <= players.size(); i++){
        answer.push_back(stand_name[i]);
    }

    return answer;
}

