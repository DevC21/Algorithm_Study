#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(string t, string p) {
    int answer = 0;
    int cur = 0;
    ll ptoll = stoll(p);
    
    while(cur + p.size() <= t.size()){
        string tmp = "";
        for(int i = cur; i < cur + p.size(); i++)
            tmp += t[i];
        
        ll tmpll = stoll(tmp);
        if(tmpll <= ptoll) answer++;
        cur++;
    }

    return answer;
}