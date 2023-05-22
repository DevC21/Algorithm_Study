#include<bits/stdc++.h>
using namespace std;

int INF = INT32_MAX / 2;
int n, m;
int D[205][205];
int nxt[205][205];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        fill(D[i]+1, D[i]+n+1, INF);
        D[i][i] = 0;
    }
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        D[a][b] = c;
        D[b][a] = c;
        nxt[a][b] = b;
        nxt[b][a] = a;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                cout << '-' << ' ';
                continue;
            }
            cout << nxt[i][j] << ' ';
        }
        cout << '\n';
    }
}