#include<bits/stdc++.h>
using namespace std;

// ī�� �����ϱ� 1�� �ݴ� ����

int n;
int P[1005];
// D[i] = i���� ī�带 ���� ���� ������ ���� �ּҰ�
int D[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(D, D+n+1, 10'000'005);

    for(int i = 1; i <= n; i++)
        cin >> P[i];

    D[0] = 0;
    D[1] = P[1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            D[i] = min(D[i - j] + P[j], D[i]);

    cout << D[n];
}