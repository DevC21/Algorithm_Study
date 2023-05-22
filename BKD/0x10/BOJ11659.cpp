#include<bits/stdc++.h>
using namespace std;

int arr[100005];
int D[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    D[1] = arr[1];

    for(int i = 2; i <= n; i++){
        D[i] = D[i-1] + arr[i];
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cout << D[b] - D[a-1] << '\n';
    }
}