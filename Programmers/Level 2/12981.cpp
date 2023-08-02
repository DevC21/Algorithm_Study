#include<bits/stdc++.h>
using namespace std;

// ������ �����ߴ� �ܾ� ���
map<string, bool> memo;
int turn[11];

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    turn[0]++;
    memo[words[0]] = true;
    int cur = 1;
    for(int i = 1; i < words.size(); i++){
        turn[cur]++;

        // �����ձ⸦ ������ ��
        if(words[i - 1].back() != words[i].front()){
            answer.push_back(cur + 1);
            answer.push_back(turn[cur]);
            break;
        }

        // ������ �����ߴ� �ܾ ������� ��
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