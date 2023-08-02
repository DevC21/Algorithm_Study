#include<bits/stdc++.h>
using namespace std;

// 이전에 등장했던 단어 기억
map<string, bool> memo;
int turn[11];

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    turn[0]++;
    memo[words[0]] = true;
    int cur = 1;
    for(int i = 1; i < words.size(); i++){
        turn[cur]++;

        // 끝말잇기를 못했을 때
        if(words[i - 1].back() != words[i].front()){
            answer.push_back(cur + 1);
            answer.push_back(turn[cur]);
            break;
        }

        // 이전에 등장했던 단어를 사용했을 때
        if(memo[words[i]]){
            answer.push_back(cur + 1);
            answer.push_back(turn[cur]);
            break;
        }
        else
            memo[words[i]] = true;

        cur++;
        cur %= n;
    }

    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}