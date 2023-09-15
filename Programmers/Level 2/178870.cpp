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
            // ������ �����ϴ� ���� ���̰� ª�� ������ ���̸� ���
            min_len = min(min_len, r - l);
        }

        if((r >= sequence.size() && tot < k) || l >= sequence.size())
            break;
        
        // �κ� ������ ���� k���� ������ �������� ��ĭ �̵�
        if(tot < k && r < sequence.size()){
            r++;
            tot += sequence[r];
        }
        // �κ� ������ ���� k���� ũ�� ������ ��ĭ �̵�
        else if(tot >= k && l < sequence.size()){
            tot -= sequence[l];
            l++;
        }
    }

    // ������ �����ϴ� ������ ���� ���̰� ª�� ������ ã�´�.
    for(auto x : lr){
        if(x.second - x.first == min_len){
            answer.push_back(x.first);
            answer.push_back(x.second);
            break;
        }
    }

    return answer;
}