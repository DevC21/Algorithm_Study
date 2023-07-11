#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[1030][1030];
int D[1030][1030];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // 현재 위치의 값에
            D[i][j] = arr[i][j];
            // 왼쪽 까지의 누적합, 위쪽 까지의 누적합을 더하고,
            D[i][j] += D[i - 1][j] + D[i][j - 1];
            // i - 1열 j - 1행의 누적합을 빼준다. (중복으로 더했기때문에)
            D[i][j] -= D[i - 1][j - 1];
        }
    }

    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        //arr[1][1] ~ arr[x2][y2]의 부분합(전체 사각형)에서
        int ans = D[x2][y2];
        //arr[1][1] ~ arr[x2][y1 - 1]의 부분합(구할 사각형의 왼쪽 부분)과
        ans -= D[x2][y1 - 1];
        //arr[1][1] ~ arr[x1 - 1][y2]의 부분합(구할 사각형의 위쪽 부분)을 빼고
        ans -= D[x1 - 1][y2];
        //arr[1][1] ~ arr[x1 - 1][y1 - 1]의 부분합(위 두 사각형이 겹치는 부분)을 더한다.
        ans += D[x1 - 1][y1 - 1];

        cout << ans << '\n';
    }
}