#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    for(auto x : scoville)
        min_pq.push(x);

    while(!min_pq.empty() && min_pq.top() < K){
        int a = min_pq.top();
        min_pq.pop();
        if(min_pq.empty())
            return -1;
        int b = min_pq.top();
        min_pq.pop();

        min_pq.push(a + (b * 2));
        answer++;
    }

    if(min_pq.empty())
        return -1;

    return answer;
}

int main(){
    int ans = solution({1, 2, 3, 9, 10, 12}, 7);

    return 0;
}