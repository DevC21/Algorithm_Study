#include<bits/stdc++.h>
using namespace std;

int n, k;
int D[10005];
int coin[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> coin[i];

    D[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = coin[i]; j <= k; j++)
        //i�� ������ ����Ͽ� j ���� ���鶧�� j - coin[i] �ݾ��� ���� �ո� �˸� �ȴ�.
            D[j] += D[j - coin[i]];

    cout << D[k] << '\n';
}