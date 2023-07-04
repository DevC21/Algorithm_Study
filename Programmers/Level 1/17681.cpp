#include<bits/stdc++.h>
using namespace std;

int n = 5;
vector<int> arr1 = {9, 20, 28, 18, 11};
vector<int> arr2 = {30, 1, 21, 17, 28};
int map1[16][16];
int map2[16][16];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i = 0; i < n; i++){
        int num1 = arr1[i];
        int num2 = arr2[i];
        for(int j = 0; j < n; j++){
            map1[i][j] = num1 % 2;
            map2[i][j] = num2 % 2;
            num1 /= 2;
            num2 /= 2;
        }
    }

    for(int i = 0; i < n; i++){
        string col = "";
        for(int j = 0; j < n; j++){
            if(map1[i][j] == 1 || map2[i][j] == 1)
                col.insert(0, "#");
            if(map1[i][j] == 0 && map2[i][j] == 0)
                col.insert(0, " ");
        }
        answer.push_back(col);
    }

    return answer;
}

int main(){
    vector<string> ans = solution(n, arr1, arr2);

    return 0;
}