#include<bits/stdc++.h>
using namespace std;

/*
D[2]�� P[2]�� D[1]+D[1]�� ū ���� �� ���̰�,

D[3]�� P[3]�� D[2]+D[1]�� ū ���� �� ���̰�,

D[4]�� P[4]�� D[3]+D[1], D[2]+D[2]�� ū ���� �� ���̴�.

D�� ����ִ� ���� �׻� �ִ밪�̱� ������,

D[a] + D[b]�� �׻� �ִ밪�� ���;� �ϸ�,

�̸� ���� D[i] = D[a] + D[i - a]���� D�� ���� �� �ִ�.

��ȭ���� D[i] = max(D[i - j] + P[j], D[i])
*/

int n;
// D[i] = i���� ī�带 ���� ���� ������ ���� �ִ�
int D[1001];
int P[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> P[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            D[i] = max(D[i - j] + P[j], D[i]);
        }
    }

    cout << D[n];
}