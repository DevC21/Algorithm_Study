#include<bits/stdc++.h>
using namespace std;

int D[1'000'005];

int solution(int x, int y, int n) {
    int answer = 0;

    fill(D+x+1, D+y+1, INT32_MAX);

    D[x] = 0;
    
    for(int i = x; i <= y; i++){
        if(D[i] != -1){
            if(i + n <= y)
                D[i + n] = min(D[i] + 1, D[i + n]);
            if(i * 2 <= y)
                D[i * 2] = min(D[i] + 1, D[i * 2]);
            if(i * 3 <= y)
                D[i * 3] = min(D[i] + 1, D[i * 3]);
            if(i + n == y || i * 2 == y || i * 3 == y)
                break;
        }
    }

    if(D[y] != INT32_MAX)
        answer = D[y];
    else
        answer = -1;

    return answer;
}