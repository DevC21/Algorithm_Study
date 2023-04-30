#include<bits/stdc++.h>
using namespace std;

int INF = INT32_MAX / 2;
int D[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fill(D[i], D[i]+n+1, INF);
    }

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(D[a][b] > c)
            D[a][b] = c;
    }

    for(int i = 1; i <= n; i++)
        D[i][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(D[j][k] > D[j][i] + D[i][k])
                    D[j][k] = D[j][i] + D[i][k];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(D[i][j] == INF) cout << "0 ";
            else cout << D[i][j] << ' ';
        }
        cout << '\n';
    }

}