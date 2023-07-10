#include<bits/stdc++.h>
using namespace std;

int n;
int D[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[1] = 1;
    D[2] = 0;
    D[3] = 1;
    D[4] = 1;

    /*
        상근이가 맨 처음에 j개의 돌을 가져갔을 때 
        D[i - 1], D[i - 3], D[i - 4]가 하나라도 0일 경우 상근이가 이긴다
        그렇지 않을 경우 창영이가 이긴다.
    */
    for (int i = 5; i <= n; i++) {
        if (D[i - 1] == 0 || D[i - 3] == 0 || D[i - 4] == 0)
            D[i] = 1; 
        else 
            D[i] = 0;
    }

    if(D[n] == 1)
        cout << "SK";
    else
        cout << "CY";
}