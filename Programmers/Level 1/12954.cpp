#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    ll num = x;
    for(int i = 0; i < n; i++){
        answer.push_back(num);
        num += x;
    }

    return answer;
}