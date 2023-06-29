#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            if(lost[i] == reserve[j]){
                answer++;
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                // erase 할 경우 lost.size()가 업데이트 됐음에도 
                // i가 가리키는 인덱스는 그대로 이므로 엉뚱한 인덱스를 가리킴
                // for문이 끝날때 i++를 하므로 -1으로 초기화 해주어야 0부터 시작함
                // j는 break가 걸리고 다시 0부터 시작하므로 상관없음
                i = -1; 
                break;
            }
        }
    }

    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            if(lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1){
                answer++;
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }

    return answer;
}