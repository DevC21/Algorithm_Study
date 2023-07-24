#include<bits/stdc++.h>
using namespace std;

int n;
int maze[1005];
int D[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(D, D+1001, INT16_MAX);

    for(int i = 0; i < n; i++)
        cin >> maze[i];

    D[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= maze[i]; j++){
            if(i + j >= n)
                break;
            D[i + j] = min(D[i] + 1, D[i + j]);
        }
    }

    if(D[n - 1] == INT16_MAX)
        cout << -1;
    else
        cout << D[n - 1];
}