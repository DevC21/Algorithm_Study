#include<bits/stdc++.h>
using namespace std;

vector<int> lottos = {44, 1, 0, 0, 31, 25};
vector<int> win_nums = {31, 10, 45, 1, 6, 19};

int arr[7] = {6, 6, 5, 4, 3, 2, 1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int unknown = 0;
    int correct = 0;
    for(auto x : lottos){
        if(x == 0)
            unknown++;
        if(find(win_nums.begin(), win_nums.end(), x) != win_nums.end())
            correct++;
    }

    answer.push_back(arr[correct]);
    answer.push_back(arr[correct+unknown]);

    return answer;
}

int main(){
    vector<int> ans = solution(lottos, win_nums);

    return 0;
}