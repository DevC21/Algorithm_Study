#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int zero_cnt, one_cnt;

void recur(int x, int y, int size){
    bool zero, one;
    zero = true;
    one = true;

    // ��ͷ� �Ѿ�� �簢���ȿ��� ���� ���ڷ� �̷���� �ִ��� �Ǻ�
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

    // ���� �� �簢��
    recur(x, y, size / 2);
    // ������ �� �簢��
    recur(x, y + size / 2, size / 2);
    // ���� �Ʒ� �簢��
    recur(x + size / 2, y, size / 2);
    // ������ �Ʒ� �簢��
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