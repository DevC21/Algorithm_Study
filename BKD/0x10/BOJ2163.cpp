#include<bits/stdc++.h>
using namespace std;

int n, m;
int D[301][301];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= 300; i++){
        D[i][1] = i - 1;
        for(int j = 2; j <= 300; j++)
            D[i][j] = D[i][j - 1] + i;
    }

    /*
        이렇게 해도 정답
        cout << n - 1 + n * (m - 1);
    */
   
    cout << D[n][m];
}