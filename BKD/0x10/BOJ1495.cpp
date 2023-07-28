#include<bits/stdc++.h>
using namespace std;

int n, s, m, ans = -1;
int V[51];
bool D[51][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m;

    for(int i = 0; i < n; i++)
        cin >> V[i];

    if(s + V[0] <= m)
        D[0][s + V[0]] = true;
    if(s - V[0] >= 0)
        D[0][s - V[0]] = true;


    for(int i = 1; i < n; i++){
        for(int j = 0; j <= m; j++){
            if(D[i - 1][j]){
                if(j + V[i] <= m)
                    D[i][j + V[i]] = true;
                if(j - V[i] >= 0)
                    D[i][j - V[i]] = true;
            }
        }
    }

    for(int i = 0; i <= m; i++){
        if(D[n - 1][i])
            ans = i;
    }
        
    if(ans == -1)
        cout << -1;
    else
        cout << ans;
}