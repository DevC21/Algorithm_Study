#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int zero_cnt, one_cnt;

void recur(int x, int y, int size){
    bool zero, one;
    zero = true;
    one = true;

    // 재귀로 넘어온 사각형안에서 단일 숫자로 이루어져 있는지 판별
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(board[i][j] == 0) one = false;
            else if(board[i][j] == 1) zero = false;
        }
    }

    if(zero == true){
        zero_cnt++;
        return;
    }
    else if(one == true){
        one_cnt++;
        return;
    }

    // 왼쪽 위 사각형
    recur(x, y, size / 2);
    // 오른쪽 위 사각형
    recur(x, y + size / 2, size / 2);
    // 왼쪽 아래 사각형
    recur(x + size / 2, y, size / 2);
    // 오른쪽 아래 사각형
    recur(x + size / 2, y + size / 2, size / 2);

}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    board = arr;

    recur(0, 0, arr.size());

    answer.push_back(zero_cnt);
    answer.push_back(one_cnt);

    return answer;
}