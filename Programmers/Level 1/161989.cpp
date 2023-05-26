#include<bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int painted = section[0] - 1;
    for(auto x : section){
        if(painted < x){
            painted = x + m - 1;
            answer += 1;
        }
    }

    return answer;
}