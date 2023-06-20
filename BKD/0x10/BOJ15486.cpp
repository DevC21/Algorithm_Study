#include<bits/stdc++.h>
using namespace std;

int t[1'500'005];
int p[1'500'005];
int D[1'500'005]; // i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익

// 로직의 변경은 없고 단순히 n의 크기만 커진 문제

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    for (int i = n; i >= 1; i--) {
        // i번째 일에 상담을 할 수 있을 경우
        // == i일 + 상담에 걸리는 기간 t[i]가 퇴사일인 n + 1을 넘지 않는 경우
        if (i + t[i] <= n + 1) {
            // i번째 일에 상담을 했을 때와 상담을 하지 않았을 때 얻을 수 있는 수익 중 최대 수익을 취함
            D[i] = max(D[i + t[i]] + p[i], D[i + 1]);
        }
        else D[i] = D[i + 1];
    }
  cout << *max_element(D, D + n + 1);
}