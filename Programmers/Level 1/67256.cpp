#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

map<int, pair<int, int>> keymap;

char distancecalc(pair<int, int> &L, pair<int, int> &R, const int &num, const string &hand){
    int LX = abs(keymap[num].X - L.X); 
    int LY = abs(keymap[num].Y - L.Y);
    int RX = abs(keymap[num].X - R.X);
    int RY = abs(keymap[num].Y - R.Y);
    if(LX + LY < RX + RY){
        L = keymap[num];
        return 'L';
    }
    else if(RX + RY < LX + LY){
        R = keymap[num];
        return 'R';
    }
    else{
        if(hand == "left"){
            L = keymap[num];
            return 'L';
        }
        else if(hand == "right"){
            R = keymap[num];
            return 'R';
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int, int> L = {3, 0};
    pair<int, int> R = {3, 2};

    int idx = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            keymap[idx] = {i, j};
            idx++;
        }
    }
    keymap[0] = {3, 1};

    for(auto x : numbers){
        if(x == 1){
            answer += 'L';
            L = keymap[1];
        }
        else if(x == 4){
            answer += 'L';
            L = keymap[4];
        }
        else if(x == 7){
            answer += 'L';
            L = keymap[7];
        }
        else if(x == 3){
            answer += 'R';
            R = keymap[3];
        }
        else if(x == 6){
            answer += 'R';
            R = keymap[6];
        }
        else if(x == 9){
            answer += 'R';
            R = keymap[9];
        }

        if(x == 2){
            answer += distancecalc(L, R, x, hand);
        }
        else if(x == 5){
            answer += distancecalc(L, R, x, hand);
        }
        else if(x == 8){
            answer += distancecalc(L, R, x, hand);
        }
        else if(x == 0){
            answer += distancecalc(L, R, x, hand);
        }
    }
    return answer;
}