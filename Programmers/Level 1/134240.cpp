#include<bits/stdc++.h>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i = 1; i < food.size(); i++){
        if(food[i] / 2 > 0){
            for(int j = 0; j < food[i] / 2; j++)
                answer += '0' + i;
        }
    }

    string tmp = answer;
    reverse(tmp.begin(), tmp.end());
    answer.append('0' + tmp);

    return answer;
}