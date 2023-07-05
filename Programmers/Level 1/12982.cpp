#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;

    sort(d.begin(), d.end());

    for(auto x : d){
        sum += x;
        if(sum > budget)
            break;
        answer++;
    }

    return answer;
}