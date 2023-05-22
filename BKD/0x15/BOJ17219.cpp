#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, string> p;
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string site, pw;
        cin >> site >> pw;
        p[site] = pw;
    }

    for(int i = 0; i < m; i++){
        string site;
        cin >> site;

        cout << p[site] << '\n';
    }
}