#include<bits/stdc++.h>
using namespace std;

bool vis[9];
int m;

int explore(int cnt, int fatigue, const vector<vector<int>> &dungeons){
    for(int i = 0; i < dungeons.size(); i++){
        if(!vis[i] && fatigue >= dungeons[i][0]){
            vis[i] = true;
            m = explore(cnt + 1, fatigue - dungeons[i][1], dungeons);
            vis[i] = false;
        }
    }
    return max(m, cnt);
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    for(int i = 0; i < dungeons.size(); i++){
        if(k >= dungeons[i][0]){
            vis[i] = true;
            explore(1, k - dungeons[i][1], dungeons);
            vis[i] = false;
        }
    }

    answer = m;
    return answer;
}