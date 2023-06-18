#include<bits/stdc++.h>
using namespace std;

string s = "one4seveneight";

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;

    for(int i = 0; i <= 9; i++)
        s = regex_replace(s, regex(num[i]), to_string(i));

    answer = stoi(s);
    return answer;
}

int main(){
    int ans = solution(s);

    return 0;
}