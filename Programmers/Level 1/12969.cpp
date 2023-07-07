#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << '*';
        }
        cout << '\n';
    }
  
    return 0;
}