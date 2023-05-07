#include<bits/stdc++.h>
using namespace std;

int n;
int D[21][21];
bool road[21][21];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
        fill(road[i]+1, road[i]+n+1, true);

    // 주어지는 값은 이미 플로이드 와샬이 적용된 최단거리 값
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> D[i][j];

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if (i == k || j == k) continue;
                // 만약 D[i][j]가 D[i][k] + D[k][j] 보다 크다면 최단 거리 값이 아니므로
                // 불가능한 경우이므로 -1을 출력하고 종료 
                if(D[i][j] > D[i][k] + D[k][j]){
                    cout << "-1\n";
                    return 0;
                }
                // i ? j까지 이동시간 D[i][j]이 
                // i ? k, k ? j까지의 이동시간의 합과 같다면 
                // i ? k ? j로 거쳐서 가는 경로이므로 
                // i ? j는 도로에 포함하지 않는다. 
                // 따라서 road[i][j]를 false로 바꾸어 ans에 합하지 않게 한다.
                if(D[i][j] == D[i][k] + D[k][j]){
                    road[i][j] = false;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(road[i][j])
                ans += D[i][j];
        }
    }

    cout << ans / 2 << '\n';
}