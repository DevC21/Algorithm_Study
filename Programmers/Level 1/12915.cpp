#include<bits/stdc++.h>
using namespace std;

int idx;

bool cmp(string s1, string s2){
    if(s1[idx] != s2[idx])
        return s1[idx] < s2[idx];
    return s1 < s2;
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}