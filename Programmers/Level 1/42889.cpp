#include<bits/stdc++.h>
using namespace std;

map<int, pair<int, int>> progress;
map<int, float> failrate;

bool cmp(int a, int b){
    if(failrate[a] != failrate[b])
        return failrate[a] > failrate[b];
    return a < b;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    int maxstage = 0;

    for(int i = 1; i <= N; i++)
        answer.push_back(i);

    for(auto x : stages){
        for(int i = 1; i <= x; i++){
            if(i > N)
                break;
            if(i == x)
                progress[i].first++;
            progress[i].second++;
        }
        maxstage = max(x, maxstage);
    }

    for(int i = maxstage + 1; i <= N; i++)
        progress[i].second++;

    for(int i = 1; i <= N; i++)
        failrate[i] = (float)progress[i].first / (float)progress[i].second;

    sort(answer.begin(), answer.end(), cmp);

    return answer;
}