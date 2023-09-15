#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    vector<pair<int, int>> lr;

    int l = 0, r = 0;
    int tot = sequence[0];
    int min_len = 1'000'005;
    while(true){
        if(tot == k){
            lr.push_back({l, r});
            // 조건을 만족하는 가장 길이가 짧은 수열의 길이를 기록
            min_len = min(min_len, r - l);
        }

        if((r >= sequence.size() && tot < k) || l >= sequence.size())
            break;
        
        // 부분 수열의 합이 k보다 작으면 오른쪽을 한칸 이동
        if(tot < k && r < sequence.size()){
            r++;
            tot += sequence[r];
        }
        // 부분 수열의 합이 k보다 크면 왼쪽을 한칸 이동
        else if(tot >= k && l < sequence.size()){
            tot -= sequence[l];
            l++;
        }
    }

    // 조건을 만족하는 수열중 가장 길이가 짧은 수열을 찾는다.
    for(auto x : lr){
        if(x.second - x.first == min_len){
            answer.push_back(x.first);
            answer.push_back(x.second);
            break;
        }
    }

    return answer;
}