#include<bits/stdc++.h>
using namespace std;

int a[500005];
int b[500005];
int c[500005];
int cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+m);

    for(int i = 0; i < n; i++){
        if(!binary_search(b, b+m, a[i])){
            c[cnt] = a[i];
            cnt++;
        }
    }

    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++){
        cout << c[i] << ' ';
    }
}