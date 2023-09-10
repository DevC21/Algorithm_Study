#include<bits/stdc++.h>
using namespace std;

// 개선할 여지가 많음

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> q;
    for(int i = 0; i < truck_weights.size(); i++)
        q.push(truck_weights[i]);

    deque<pair<int, int>> trucks;
    int cnt = 0;
    int cur_weight = 0;
    while(true){
        if(q.empty() && trucks.empty())
            break;
        cnt++;
        if(!trucks.empty()){
            int pop_cnt = 0;
            for(int i = 0; i < trucks.size(); i++){
                trucks[i].second++;
                if(trucks[i].second == bridge_length)
                    pop_cnt++;
            }
            for(int i = 0; i < pop_cnt; i++){
                cur_weight -= trucks.front().first;
                trucks.pop_front();
            }
        }
        
        if(!q.empty() && q.front() + cur_weight <= weight){
            trucks.push_back({q.front(), 0});
            cur_weight += q.front();
            q.pop();
        }
    }

    answer = cnt;
    return answer;
}