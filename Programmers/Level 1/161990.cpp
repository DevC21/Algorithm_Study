#include<bits/stdc++.h>
using namespace std;

vector<string> wallpaper = {".#...", "..#..", "...#."};

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int lux = 51, luy = 51, rdx = 0, rdy = 0;
    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[i].size(); j++){
            if(wallpaper[i][j] == '#'){
                lux = min(lux, i);
                luy = min(luy, j);
                rdx = max(rdx, i);
                rdy = max(rdy, j);
            }
        }
    }

    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx + 1);
    answer.push_back(rdy + 1);
    return answer;
}

int main(){
    vector<int> ans = solution(wallpaper);
    cout << 0;
}