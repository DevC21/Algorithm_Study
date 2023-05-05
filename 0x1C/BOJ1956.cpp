#include<bits/stdc++.h>
using namespace std;

int INF = INT32_MAX / 2;
int v, e;
int ans = INF;
int D[405][405];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for(int i = 1; i <= v; i++){
        fill(D[i]+1, D[i]+v+1, INF);
        D[i][i] = 0;
    }


    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        D[a][b] = c;
    }

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            for(int k = 1; k <= v; k++){
                if(D[j][k] > D[j][i] + D[i][k])
                    D[j][k] = D[j][i] + D[i][k];
            }
        }
    }

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            if(D[i][j] == INF || D[i][j] == 0)
                continue;
            int cycle = D[i][j] + D[j][i];
            if(cycle < ans)
                ans = cycle;
        }
    }

    if(ans == INF) cout << -1;
    else cout << ans;
}