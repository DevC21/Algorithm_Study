#include<bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> solution(ll n) {
    vector<int> answer;

    while(n != 0){
        answer.push_back(n % 10);
        n /= 10;
    }

    return answer;
}