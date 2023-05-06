#include<bits/stdc++.h>
using namespace std;

int INF = INT32_MAX / 2;
int n, m, k;
int D[255][255]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fill(D[i], D[i]+n+1, INF);
        D[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int u, v, b;
        cin >> u >> v >> b;

        if(b == 0){
            D[u][v] = 0;
            D[v][u] = 1;
        }
        else if(b == 1){
            D[u][v] = 0;
            D[v][u] = 0;
        }
    }   

    for(int i = 1; i <=n ; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(D[j][k] > D[j][i] + D[i][k])
                    D[j][k] = D[j][i] + D[i][k];
            }
        }
    }

    cin >> k;
    
    for(int i = 0; i < k; i++){
        int s, e;
        cin >> s >> e;
        cout << D[s][e] << '\n';
    }

}