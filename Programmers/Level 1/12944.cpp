#include<bits/stdc++.h>
using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    for(auto x : arr)
        answer += x;

    answer /= arr.size();
    
    return answer;
}