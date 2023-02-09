#include<bits/stdc++.h>
using namespace std;

stack<pair<int,int>> tower;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    tower.push({100000001, 0});

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        while (tower.top().first < x)
            tower.pop();
        cout << tower.top().second << " ";
        tower.push({x, i});
    }
}