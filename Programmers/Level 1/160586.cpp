#include<bits/stdc++.h>
using namespace std;

map<char, int> keys;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    for(int i = 0; i < keymap.size(); i++){
        for(int j = 0; j < keymap[i].size(); j++){
            if(keys[keymap[i][j]] == 0)
                keys[keymap[i][j]] = j + 1;
            else
                keys[keymap[i][j]] = min(keys[keymap[i][j]], j + 1);
        }
    }

    for(int i = 0; i < targets.size(); i++){
        bool chk = false;
        int ans = 0;
        for(int j = 0; j < targets[i].size(); j++){
            if(keys[targets[i][j]] == 0){
                chk = true;
                break;
            }
            ans += keys[targets[i][j]];
        }
        if(chk)
            answer.push_back(-1);
        else
            answer.push_back(ans);
    }

    return answer;
}