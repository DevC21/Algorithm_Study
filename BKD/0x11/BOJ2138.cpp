#include<bits/stdc++.h>
using namespace std;

int n, ans = INT32_MAX, cnt = 0;
string st, ed, tmp;

void solve(bool first){
    tmp = st;
    cnt = 0;
    // 첫번째 스위치를 작동하고 시작할 경우
    if(first == true){
        if(tmp[0] == '0') tmp[0] = '1';
        else tmp[0] = '0';
        if(tmp[1] == '0') tmp[1] = '1';
        else tmp[1] = '0';
        cnt++;
    }

    for(int i = 1; i < n; i++){
        if(tmp[i - 1] != ed[i - 1]){
            // i - 1번째 전구켜기
            if(tmp[i - 1] == '0') tmp[i - 1] = '1';
            else tmp[i - 1] = '0';
            // i번째 전구켜기
            if(tmp[i] == '0') tmp[i] = '1';
            else tmp[i] = '0';
            // i + 1번째 전구켜기(n - 1번째 스위치까지)
            if(i < n - 1){
                if(tmp[i + 1] == '0') tmp[i + 1] = '1';
                else tmp[i + 1] = '0';
            }
            // 누른 횟수 증가
            cnt++;
        }
    }

    // 결과가 목표값과 같으면 갱신
    if(tmp == ed)
        ans = min(ans, cnt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> st;
    cin >> ed;

    // 그냥 시작할 경우
    solve(false);
    // 첫번째 스위치를 작동하고 시작할 경우
    solve(true);
    
    if(ans != INT32_MAX)
        cout << ans;
    else
        cout << -1;
}