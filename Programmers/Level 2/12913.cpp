#include<bits/stdc++.h>
using namespace std;

int D[100'005][4];

int solution(vector<vector<int> > land){
    int answer = 0;

    D[0][0] = land[0][0];
    D[0][1] = land[0][1];
    D[0][2] = land[0][2];
    D[0][3] = land[0][3];

    for(int i = 1; i < land.size(); i++){
        D[i][0] += max({D[i-1][1], D[i-1][2], D[i-1][3]}) + land[i][0];
        D[i][1] += max({D[i-1][0], D[i-1][2], D[i-1][3]}) + land[i][1];
        D[i][2] += max({D[i-1][0], D[i-1][1], D[i-1][3]}) + land[i][2];
        D[i][3] += max({D[i-1][0], D[i-1][1], D[i-1][2]}) + land[i][3];
    }

    for(int i = 0; i < 4; i++)
        answer = max(D[land.size() - 1][i], answer);
    return answer;
}