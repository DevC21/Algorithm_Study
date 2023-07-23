#include<bits/stdc++.h>
using namespace std;

int n, m;
int maze[1005][1005];
int D[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> maze[i][j];

        
    D[1][1] = maze[1][1];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            D[i][j] = max({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]}) + maze[i][j];

    cout << D[n][m];
}