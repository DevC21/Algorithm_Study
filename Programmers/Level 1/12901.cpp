#include<bits/stdc++.h>
using namespace std;

vector<string> week = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
    string answer = "";

    int day = 0;

    for(int i = 0; i < a - 1; i++)
        day += month[i];

    day += b;

    answer = week[day % 7];

    return answer;
}