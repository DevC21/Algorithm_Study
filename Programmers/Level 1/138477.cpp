#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i < score.size(); i++){
        if(i < k) pq.push(score[i]);
        else{
            if(score[i] > pq.top()){
                pq.pop();
                pq.push(score[i]);
            }
        }

        answer.push_back(pq.top());
    }

    return answer;
}