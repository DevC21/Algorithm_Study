#include<bits/stdc++.h>
using namespace std;

int answer = 0;

void DFS(int idx, int sum, const vector<int> &numbers, const int &target){
    if(idx == numbers.size() - 1){
        if(sum == target)
            answer++;
        return;
    }

    DFS(idx + 1, sum + numbers[idx + 1], numbers, target);
    DFS(idx + 1, sum - numbers[idx + 1], numbers, target);
}

int solution(vector<int> numbers, int target) {
    DFS(0, +numbers[0], numbers, target);
    DFS(0, -numbers[0], numbers, target);

    return answer;
}