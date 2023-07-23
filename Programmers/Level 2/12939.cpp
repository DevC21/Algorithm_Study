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

string solution(string s) {
    string answer = "";

    vector<string> nums = split(s, " ");

    int max = -INT32_MAX;
    int min = INT32_MAX;
    
    for(auto x : nums){
        int integer_x = stoi(x);
        if(max < integer_x)
            max = integer_x;
        if(min > integer_x)
            min = integer_x;
    }

    answer = to_string(min) + ' ' + to_string(max);

    return answer;
}