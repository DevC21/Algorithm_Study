#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n, r;
int D[31][31];

// 조합 nCr
// n개중 r개를 뽑는 방법의 수는 nCr개
// nCr = n-1Cr-1 + n-1Cr로 쪼갤 수 있다.
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for(int i = 1; i < 30; i++) {
        D[i][i] = 1;
        D[i][1] = i;
    }

    for (int i = 2; i < 30; i++) {
        // n개 보다 더 많이 뽑을 수는 없고 i == j 일때는 이미 위에서 계산함
		for (int j = 2; j < i; j++) {
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
		}
	}

    while(t--){
        cin >> r >> n;
        cout << D[n][r] << '\n';
    }
}