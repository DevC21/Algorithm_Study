#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
int answer = 0;
int n;

void DFS(vector<int> &number, int sum, int cur, int idx){
    if(cur == 3){
        if(sum == 0)
            answer++;
        return;
    }

    for(int i = idx; i < n; i++)
        DFS(number, sum + number[i], cur + 1, i + 1);
}

int solution(vector<int> number) {
    n = number.size();
    // number = 입력으로 주어진 number 벡터
    // number[i] = 선택한 벡터 원소의 값
    // 1 = 현재 고른 갯수 (1개)
    // i + 1 = i보다 1 큰 인덱스에서 DFS를 시작
    //         (같은 원소를 다시 세지 않기위해)
    for(int i = 0; i < n; i++)
        DFS(number, number[i], 1, i + 1);

    return answer;
}