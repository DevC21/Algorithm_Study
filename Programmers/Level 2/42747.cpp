#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int len = citations.size();
    
    // H-Index는 citations의 크기를 넘지않는다.
    for(int i = 0; i < len; i++){
        // citations[i]번 이상 인용된 논문이 citations[i]편 이상인지 검사
        if(len - i >= citations[i])
            answer = max(citations[i], answer);
        // citations[i]번 이상 인용된 논문이 citations[i]편 미만이라면 
        // 남은 논문의 갯수가 H-index가 됨
        else{ 
            answer = max(len - i, answer);
            break;
        }
    }

    return answer;
}