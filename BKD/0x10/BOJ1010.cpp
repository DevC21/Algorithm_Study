#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n, r;
int D[31][31];

// ���� nCr
// n���� r���� �̴� ����� ���� nCr��
// nCr = n-1Cr-1 + n-1Cr�� �ɰ� �� �ִ�.
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for(int i = 1; i < 30; i++) {
        D[i][i] = 1;
        D[i][1] = i;
    }

    for (int i = 2; i < 30; i++) {
        // n�� ���� �� ���� ���� ���� ���� i == j �϶��� �̹� ������ �����
		for (int j = 2; j < i; j++) {
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
		}
	}

    while(t--){
        cin >> r >> n;
        cout << D[n][r] << '\n';
    }
}