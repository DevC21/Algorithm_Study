#include<bits/stdc++.h>
using namespace std;

int INF = INT32_MAX / 2;
int D[105][105];
int nxt[105][105];

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

        if(D[a][b] > c){
            D[a][b] = c;
            nxt[a][b] = b;
        }
    }

    for(int i = 1; i <= n; i++)
        D[i][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(D[j][k] > D[j][i] + D[i][k]){
                    D[j][k] = D[j][i] + D[i][k];
                    nxt[j][k] = nxt[j][i];
                }
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

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(D[i][j] == INF || D[i][j] == 0){
                cout << "0\n";
                continue;
            }
            int a = i, c = 0;

            vector<int> path;
            path.push_back(i);

            while(c != j){
                c = nxt[a][j];
                a = nxt[a][j];
                path.push_back(a);
            }

            cout << path.size() << ' ';
            for(auto x : path){
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}