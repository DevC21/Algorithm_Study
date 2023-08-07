#include<bits/stdc++.h>
using namespace std;

map<int, int> tangerine_size;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    vector<int> sizes;
    int sum = 0;

    // 사이즈별 개수 저장
    for(auto x : tangerine)
        tangerine_size[x]++;

    // 사이즈별 개수를 정렬하기 위해 벡터에 저장
    for(auto x : tangerine_size)
        sizes.push_back(x.second);

    // 내림차순 정렬
    sort(sizes.rbegin(), sizes.rend());

    // 제일 많은 사이즈부터 하나씩 종류 추가
    // k보다 개수가 많아지면 break
    for(int i = 0;  i <= sizes.size(); i++){
        sum += sizes[i];
        answer++;
        if(sum >= k)
            break;
    }

    return answer;
}