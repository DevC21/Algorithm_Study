#include<bits/stdc++.h>
using namespace std;

vector<string> split(string s, string sep){
    vector<string> ret;
    int pos = 0;
    while(pos < s.size()){
        int nxt_pos = s.find(sep, pos);
        if(nxt_pos == -1) nxt_pos = s.size();
        if(nxt_pos - pos > 0)
            ret.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + sep.size();
    }
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string, string>> q;
    map<string, string> m;

    for(auto x : record){
        vector<string> tmp = split(x, " ");

        if(tmp[0] == "Enter"){
            q.push({tmp[0], tmp[1]});
            m[tmp[1]] = tmp[2];
        }
        else if(tmp[0] == "Leave"){
            q.push({tmp[0], tmp[1]});
        }
        else if(tmp[0] == "Change")
            m[tmp[1]] = tmp[2];
    }

    while(!q.empty()){
        if(q.front().first == "Enter")
            answer.push_back(m[q.front().second] +"님이 들어왔습니다.");
        else
            answer.push_back(m[q.front().second] +"님이 나갔습니다.");
        q.pop();
    }

    return answer;
}