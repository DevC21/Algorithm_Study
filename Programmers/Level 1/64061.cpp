#include<bits/stdc++.h>
using namespace std;

stack<int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    for(auto x : moves){
        x--;
        for(int i = 0; i < board.size(); i++){
            if(board[i][x] != 0){
                if(!s.empty()){
                    if(s.top() == board[i][x]){
                        s.pop();
                        answer += 2;
                        board[i][x] = 0;
                        break;
                    }
                }
                s.push(board[i][x]);
                board[i][x] = 0;
                break;
            }
        }
    }

    return answer;
}