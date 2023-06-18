#include<bits/stdc++.h>
using namespace std;
#define Y first
#define X second

int n;
vector<pair<int, int>> coordinate;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        coordinate.push_back({y, x});
    }

    sort(coordinate.begin(), coordinate.end());

    for(auto XY : coordinate)
        cout << XY.X << ' ' << XY.Y << '\n';
}