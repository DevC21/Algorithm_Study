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

map<string, int> inout_time;
map<string, bool> inout;
map<string, int> parkingtime;


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    for(auto x : records){
        vector<string> record = split(x, " ");

        string hour = "";
        hour += record[0][0];
        hour += record[0][1];
        string min = "";
        min += record[0][3];
        min += record[0][4];

        if(record[2] == "IN"){
            inout_time[record[1]] = (stoi(hour) * 60 + stoi(min));
            inout[record[1]] = true;
        }
        else if(record[2] == "OUT"){
            parkingtime[record[1]] += (stoi(hour) * 60 + stoi(min)) - inout_time[record[1]]; 
            inout[record[1]] = false;
        }
    }

    for(auto x : inout){
        if(x.second)
            parkingtime[x.first] += (23 * 60 + 59) - inout_time[x.first]; 
    }

    for(auto x : parkingtime){
        if(x.second <= fees[0])
            answer.push_back(fees[1]);
        else{
            if((x.second - fees[0]) % fees[2] != 0)
                answer.push_back(fees[1] + (((x.second - fees[0]) / fees[2] + 1) * fees[3]));
            else
                answer.push_back(fees[1] + ((x.second - fees[0]) / fees[2] * fees[3]));
        }
            
    }

    return answer;
}