#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10001];
// D 배열은 (인덱스, 몇번 연속으로 마셨는지) 중에서 최댓값을 나타낸다.
int D[10001][3];

// 비슷한 문제인 2579(계단 오르기)와 다른 점은, 와인은 계속해서 안 마실 수도 있다는 것
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    D[1][0] = 0;
    D[1][1] = arr[1];
    D[1][2] = 0;

    for(int i = 2; i <= n; i++){
        //마시지 않을 때 : D[i-1][0~2] 중에서 최댓값
        D[i][0] = max({D[i-1][0], D[i-1][1], D[i-1][2]});
        //1번 연속 마실 때 : D[i-1][0] (그 전에 마시지 않아야 하므로) + arr[i]
        D[i][1] = D[i-1][0] + arr[i];
        //2번 연속 마실 때 : D[i-1][1] (그 전에 한 번 마셔야 하므로) + arr[i]
        D[i][2] = D[i-1][1] + arr[i];
    }

    cout << max({D[n][0], D[n][1], D[n][2]});
}