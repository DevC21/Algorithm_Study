#include<bits/stdc++.h>
using namespace std;

deque<int> dq;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    for(auto x : priorities)
        dq.push_back(x);

    while(true){
        bool exec = true;
        for(int i = 1; i < dq.size(); i++){
            if(dq[i] > dq.front()){
                exec = false;
                break;
            }
        }

        if(location == 0 && exec){
            answer++;
            break;
        }

        if(exec){
            dq.pop_front();
            answer++;
        }
        else{
            int tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
        }
        location--;
        if(location < 0)
            location = dq.size() - 1;
    }

    return answer;
}