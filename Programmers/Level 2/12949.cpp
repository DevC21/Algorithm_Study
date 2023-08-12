#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for(int i = 0; i < arr1.size(); i++){
        vector<int> tmp;
        for(int j = 0; j < arr2[0].size(); j++){ // arr2의 열 길이만큼
            int x = 0;
            for(int k = 0; k < arr1[0].size(); k++) // arr1의 행 길이 == arr2의 열 길이만큼
                // arr1[i][k] = i행 k열 arr2[k][j] = k행 j열
                x += arr1[i][k] * arr2[k][j];
            tmp.push_back(x);
        }
        answer.push_back(tmp);
    }

    return answer;
}