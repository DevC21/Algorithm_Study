#include<bits/stdc++.h>
using namespace std;

map<string, int> id_parsing;
map<int, int> reportcnt;
vector<int> mailing[1001];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    for(int i = 0; i < id_list.size(); i++)
        id_parsing[id_list[i]] = i;

    for(auto x : report){
        int sep = x.find(' ');
        string reporter = x.substr(0, sep);
        string reported = x.substr(sep + 1, x.size() - 1);
        if(find(mailing[id_parsing[reporter]].begin(), 
                mailing[id_parsing[reporter]].end(), 
                id_parsing[reported]) != mailing[id_parsing[reporter]].end())
            continue;
        reportcnt[id_parsing[reported]]++;
        mailing[id_parsing[reporter]].push_back(id_parsing[reported]);
    }

    for(int i = 0; i < id_list.size(); i++){
        int cnt = 0;
        for(int j = 0; j < mailing[i].size(); j++){
            if(reportcnt[mailing[i][j]] >= k)
                cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}