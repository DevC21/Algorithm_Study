#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> coordinate;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        coordinate.push_back({x, y});
    }

    sort(coordinate.begin(), coordinate.end());

    for(auto xy : coordinate)
        cout << xy.X << ' ' << xy.Y << '\n';
}