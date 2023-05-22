#include<bits/stdc++.h>
using namespace std;

pair<int, int> L[1000005];
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> L[i].first >> L[i].second;
    }

    sort(L, L+n);

    int l = -(1e9+1); // -1,000,000,001
    int r = -(1e9+1);

    for(int i = 0; i < n; i++){
        // r = 현재 구간의 오른쪽 끝 L[i].first = 이번 선의 왼쪽 끝
        // r < L[i].first 현재 구간의 오른쪽 끝과 이번 선의 왼쪽 끝이 떨어져 있어서 합칠 수 없음
        if(r < L[i].first){
            //정답에 현재 구간의 길이를 더하고 새로운 구간을 설정
            ans += r-l;

            l = L[i].first;
            r = L[i].second;
        }
        else{
            // 합치는게 가능할 때, 현재 구간의 오른쪽 끝을 확장 가능 하다면 확장
            r = max(r, L[i].second);
        }
    }
    ans += r-l;

    cout << ans;
}