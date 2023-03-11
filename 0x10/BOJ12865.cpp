#include<bits/stdc++.h>
using namespace std;
#define W first
#define V second

pair<int, int> item[105];
int D[105][100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> item[i].W >> item[i].V;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j - item[i].W >= 0){
                D[i][j] = max(D[i-1][j], D[i-1][j - item[i].W] + item[i].V);
            }
            else {
                D[i][j] = D[i-1][j];
            }
        }
    }

    cout << D[n][k];
}