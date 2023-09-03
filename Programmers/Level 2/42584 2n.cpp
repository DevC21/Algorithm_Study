#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int arr[100'005];
    // 주식을 산 시간 / 가격
    stack<pair<int, int>> s;

    for(int i = 0; i < prices.size(); i++){
        if(!s.empty()){
            // 스택의 맨 위의 가격이 현재 가격보다 비싸면 주식이 내려간 것이므로
            // 현재 가격보다 싸거나 같은 시점이 나올때까지 pop한다.
            while(!s.empty() && s.top().second > prices[i]){
                // 주식을 산 시점에 몇 초 동안 떨어지지 않았는지 기록
                // i(현재시간) - s.top().first(샀을때 시간)
                arr[s.top().first] = i - s.top().first;
                s.pop();
            }
        }
        s.push({i, prices[i]});
    }

    // 위 과정을 모두 거치고 스택이 비어 있지 않다면
    // 스택에 남아있는 주식은 모두 끝까지 가격이 떨어지지 않은 주식이므로
    // 전체 시간(prices.size()) - s.top().first(샀을때 시간) - 1을 기록 해준다.
    if(!s.empty()){
        while(!s.empty()){
            arr[s.top().first] = prices.size() - s.top().first - 1;
            s.pop();
        }
    }

    for(int i = 0; i < prices.size(); i++)
        answer.push_back(arr[i]);

    return answer;
}