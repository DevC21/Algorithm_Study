#include<bits/stdc++.h>
using namespace std;

set<int> s;
int elements_size;

void func(int len, const vector<int> &elements){
    // 0번 인덱스부터 elements_size - 1 인덱스까지 반복
    for(int i = 0; i < elements_size; i++){
        int sum = 0;
        // i번 인덱스부터 시작하는 len 길이의 연속 부분 수열의 합을 구함
        // elements에 같은 수열이 2번 들어가 있기 때문에
        // j가 elements_size보다 크더라도 원형 수열을 참조하는 것처럼 구현됨
        for(int j = i; j < i + len; j++)
            sum += elements[j];

        // set에 구한 합을 넣어 중복 제거
        s.insert(sum);
    }
}

int solution(vector<int> elements){
    int answer = 0;

    // 원형 수열로 만들기 전 원래 길이를 기억
    elements_size = elements.size();
    
    // 원형 수열로 만들기 위해 elements 수열을 한번 더 넣어줌
    for(int i = 0; i < elements_size; i++)
        elements.push_back(elements[i]);

    // 길이 1부터 수열의 길이만큼 반복
    for(int i = 1; i <= elements_size; i++)
        func(i, elements);

    answer = s.size();
    return answer;
}