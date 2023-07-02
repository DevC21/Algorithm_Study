#include<bits/stdc++.h>
using namespace std;

vector<string> participant = {"leo", "kiki", "eden"};
vector<string> completion = {"eden", "kiki"};

map<string, int> cnt;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(auto x : participant)
        cnt[x]++;

    for(auto x : completion)
        if(cnt[x] > 0)
            cnt[x]--;
 
    for(auto x : participant)
        if(cnt[x] != 0)
            answer = x;
        
    return answer;
}