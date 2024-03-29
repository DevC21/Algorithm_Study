#include<bits/stdc++.h>
using namespace std;

int t, n;
int D[10005][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    D[1][1] = 1;

    D[2][1] = 1;
    D[2][2] = 1;
    
    D[3][1] = 1;
    D[3][2] = 1;
    D[3][3] = 1;

    for(int i = 4; i <= 10000; i++){
        // n를 만들 수 있는 식 중에서
        // 1로 끝나는 식은 n - 1을 만드는 식에서 1을 더하는 식이다.
        D[i][1] = D[i - 1][1];
        // 2로 끝나는 식은 n - 2을 만드는 식에서 1로 끝나는 식과 2로 끝나는 식에 2를 더하는 식
        D[i][2] = D[i - 2][1] + D[i - 2][2];
        // 3으로 끝나는 식은 n - 3을 만드는 식에서 1로 끝나는 식과 2로 끝나는 식, 3으로 끝나는 식에 3를 더하는 식
        D[i][3] = D[i - 3][1] + D[i - 3][2] + D[i - 3][3];
    }

    while(t--){
        cin >> n;
        cout << D[n][1] + D[n][2] + D[n][3] << '\n';
    }

}