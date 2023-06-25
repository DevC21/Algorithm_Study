#include<bits/stdc++.h>
using namespace std;

set<int> result;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for(int i = 0; i < numbers.size(); i++){
        for(int j = i + 1; j < numbers.size(); j++){
            result.insert(numbers[i] + numbers[j]);
        }
    }

    for(auto x : result)
        answer.push_back(x);

    return answer;
}