#include<bits/stdc++.h>
using namespace std;
#define MAX 10001

int n, k;
int D[10005];
int coin[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> coin[i];

    D[0] = 0;
    for(int i = 1; i <= MAX; i++)
        D[i] = MAX; //D[0]�� ������ ���� ���� 10001(�Ұ����� ���)

    for (int i = 1; i <= n; i++)
        for (int j = coin[i]; j <= k; j++)            
            //D[j] : j���� ���� �� �ִ� ������ �ּ� ����
            //D[j - coin[i] : j���� ���鶧 coin[i]���� �� �� ���
            D[j] = min(D[j], D[j - coin[i]] + 1);

    if(D[k] == MAX)
        cout << -1;
    else
        cout << D[k] << '\n';
}