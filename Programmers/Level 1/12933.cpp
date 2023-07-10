#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solution(ll n) {
    ll answer = 0;
    
    string s = to_string(n);

    sort(s.begin(), s.end(), greater<>());

    answer = stoll(s);
    
    return answer;
}