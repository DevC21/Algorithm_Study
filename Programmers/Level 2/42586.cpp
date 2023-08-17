#include<bits/stdc++.h>
using namespace std;

queue<int> q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    

    for(int i = 0; i < progresses.size(); i++)
        q.push(i);

    while(!q.empty()){
        int deploy = 0;
        while(progresses[q.front()] >= 100){
            q.pop();
            deploy++;
            if(q.empty())
                break;
        }

        if(deploy != 0)
            answer.push_back(deploy);
        
        for(int i = 0; i < progresses.size(); i++)
            progresses[i] += speeds[i];
    }

    return answer;
}

int main(){
    vector<int> ans = solution({93, 30, 55}, {1, 30, 5});
}