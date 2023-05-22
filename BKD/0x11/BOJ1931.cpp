#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int first, second;
        cin >> first >> second;

        m.push_back({second, first}); // 종료시간을 기준으로 sort
    }

    sort(m.begin(), m.end());

    int mcnt = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(cur > m[i].second)
            continue;
        mcnt++;
        cur = m[i].first;
    }

    cout << mcnt;
}