#include<bits/stdc++.h>
using namespace std;

map<char, bool> skill_acquire;
map<char, int> skill_order;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(int i = 0; i < skill.size(); i++){
        skill_acquire[skill[i]] = false;
        skill_order[skill[i]] = i;
    }

    for(int i = 0; i < skill_trees.size(); i++){
        for(int i = 0; i < skill.size(); i++)
            skill_acquire[skill[i]] = false;
        bool possible = true;
        for(auto x : skill_trees[i]){
            if(skill_acquire.find(x) != skill_acquire.end()){
                if(skill_order[x] == 0)
                    skill_acquire[x] = true;
                else{
                    for(int i = 0; i < skill_order[x]; i++){
                        if(!skill_acquire[skill[i]]){
                            possible = false;
                            break;
                        }
                    }
                    if(possible)
                        skill_acquire[x] = true;
                    else
                        break;
                }
            }
        }
        if(possible)
            answer++;
    }

    return answer;
}