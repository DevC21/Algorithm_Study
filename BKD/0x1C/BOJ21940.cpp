#include<bits/stdc++.h>
using namespace std;

int INF = INT32_MAX / 2;
int n, m, Totalk;
int D[205][205];
int C[205];
vector<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        fill(D[i]+1, D[i]+n+1, INF);
        D[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b, t;
        cin >> a >> b >> t;

        if(D[a][b] > t){
            D[a][b] = t;
        }
    }

    cin >> Totalk;

    for(int i = 0; i < Totalk; i++){
        int c;
        cin >> c;
        C[i] = c;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(D[j][k] > D[j][i] + D[i][k]){
                    D[j][k] = D[j][i] + D[i][k];
                }
            }
        }
    }
    
    int minX = INF;

    for(int i = 1; i <= n; i++){
        int MAX = 0;
		for (int j = 0; j < Totalk; j++) {
			if (D[i][C[j]] != INF && D[C[j]][i] != INF) {
				MAX = max(D[i][C[j]] + D[C[j]][i], MAX);
			}
		}

        if(MAX < minX){
            ans.clear();
            minX = MAX;
            ans.push_back(i);
        }
        else if(MAX == minX){
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    for(auto x : ans)
        cout << x << ' ';
}