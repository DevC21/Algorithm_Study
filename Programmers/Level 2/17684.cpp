#include<bits/stdc++.h>
using namespace std;

map<string, int> dic;

vector<int> solution(string msg) {
    vector<int> answer;

    for(int i = 1; i <= 26; i++){
        string s = "";
        s += ('A' + i - 1);
        dic[s] = i;   
    }

    for(int i = 0; i < msg.size(); i++){
        string s = "";
        int num = 0;
        s += msg[i];

        int idx = 1;
        while(dic.find(s) != dic.end()){
            num = dic[s];
            s += msg[i + idx];
            idx++;
        }

        if(s.size() > 2)
            i += s.size() - 2;

        dic[s] = dic.size() + 1;
        answer.push_back(num);
    }
    
    return answer;
}