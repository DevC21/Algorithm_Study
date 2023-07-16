#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 x에 있다";

    int idx = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer.replace(answer.find("x"), 1, to_string(idx));

    return answer;
}