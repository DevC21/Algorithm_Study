#include<bits/stdc++.h>
using namespace std;

int INF = INT32_MAX / 2;
int D[105][105];
int item[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++){
        fill(D[i], D[i]+n+1, INF);
    }

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        item[i] = t;
    }

    for(int i = 0; i < r; i++){
        int a, b, l;
        cin >> a >> b >> l;

        if(D[a][b] > l){
            D[a][b] = l;
            D[b][a] = l;
        }
    }

    for(int i = 1; i <= n; i++) D[i][i] = 0;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(D[j][k] > D[j][i] + D[i][k]){
                    D[j][k] = D[j][i] + D[i][k];
                }
            }
        }
    }

    int get_max = -1;
    for(int i = 1; i <= n; i++){
        int itemcnt = 0;
        for(int j = 1; j <= n; j++){
            if(D[i][j] <= m){
               itemcnt += item[j];
            }
        }
        get_max = max(get_max, itemcnt);
    }

    cout << get_max << '\n';
}