#include<bits/stdc++.h>
using namespace std;

// BOJ17298 오큰수와 똑같은 문제
// 다만 answer에 0번째 인덱스부터 순서대로 오큰수가 들어가야 하므로
// answer를 한번 뒤집어줘야함

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> s;

    for(int i = numbers.size() - 1; i >= 0; i--){
        while(!s.empty()){
            if(s.top() > numbers[i])
                break;
            s.pop();
        }
        
        if(s.empty()) answer.push_back(-1);
        else answer.push_back(s.top());

        s.push(numbers[i]);
    }

    reverse(answer.begin(), answer.end());
    return answer;
}