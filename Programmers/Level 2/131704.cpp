#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    queue<int> main;
    stack<int> sub;

    for(int i = 1; i <= order.size(); i++)
        main.push(i);

    int cur = 0;
    while(true){
        if(main.empty() && (sub.empty() || sub.top() != order[cur]))
            break;

        if(main.front() == order[cur]){
            main.pop();
            answer++;
            cur++;
        }
        else if(main.front() != order[cur]){
            sub.push(main.front());
            main.pop();
        }

        while(!sub.empty() && sub.top() == order[cur]){
            if(sub.top() == order[cur]){
                sub.pop();
                answer++;
                cur++;
            }
        }
    }
    
    return answer;
}