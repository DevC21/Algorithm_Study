#include<bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2){
    if(s1 + s2 > s2 + s1)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> v;
    for(auto x : numbers)
        v.push_back(to_string(x));

    sort(v.begin(), v.end(), cmp);

    if(v[0] == "0")
        return "0";

    for(auto x : v)
        answer += x;

    return answer;
}