#include<bits/stdc++.h>
using namespace std;

int first[] = {1, 2, 3, 4, 5};
int second[] = {2, 1, 2, 3, 2, 4, 2, 5};
int third[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int score[3];

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int maxscore = 0;

    for(int i = 0; i < answers.size(); i++){
        if(first[i % 5] == answers[i])
            score[0]++;
        if(second[i % 8] == answers[i])
            score[1]++;
        if(third[i % 10] == answers[i])
            score[2]++;
    }

    for(int i = 0; i < 3; i++)
        maxscore = max(maxscore, score[i]);

    for(int i = 0; i < 3; i++)
        if(maxscore == score[i])
            answer.push_back(i + 1);

    return answer;
}