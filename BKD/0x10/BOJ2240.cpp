#include<bits/stdc++.h>
using namespace std;

int t, w, ans = 0;
int D[2][31][1001];
int arr[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> t >> w;

	for (int i = 1; i <= t; i++)
		cin >> arr[i];

	for (int j = 0; j <= w; j++){
		for (int i = 1; i <= t; i++){
			if (j == 0){
                //j == 0일때는 1번 나무에 위치함
                if(arr[i] == 1)
				    D[0][j][i] = D[0][j][i - 1] + 1;
                else
                    D[0][j][i] = D[0][j][i - 1];
			}
			else{
				//j > 0 일때, 위치 움직임or안움직임, 받음or못받음을 확인
                if(arr[i] == 1){
                    D[0][j][i] = max(D[0][j][i - 1] + 1, D[1][j - 1][i - 1] + 1);
                    D[1][j][i] = max(D[1][j][i - 1], D[0][j - 1][i - 1]);
                }
                else{
                    D[0][j][i] = max(D[0][j][i - 1], D[1][j - 1][i - 1]);
                    D[1][j][i] = max(D[1][j][i - 1] + 1, D[0][j - 1][i - 1] + 1);
                }
				// D[현재 위치][이동횟수][흐른 시간] = 
				// (이동하지않고 시간만 1초 흐름 + i번째 입력과 현재 위치가 같은가?), 
				// (이동했고, 1초 흐름 + i번째 입력과 현재 위치가 같은가?) 중 큰 값
			}
		}
	}

	for (int i = 0; i < 2; i++){
		for (int j = 0; j <= w; j++){
        	// 마지막에 가능한 모든 이동횟수(j)와, 위치(1, 2)중 가장 큰 값을 출력한다.
			ans = max(ans, D[i][j][t]);
		}
	}

    cout << ans;
}