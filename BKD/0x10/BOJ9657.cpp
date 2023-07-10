#include<bits/stdc++.h>
using namespace std;

int n;
int D[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[1] = 1;
    D[2] = 0;
    D[3] = 1;
    D[4] = 1;

    /*
        ����̰� �� ó���� j���� ���� �������� �� 
        D[i - 1], D[i - 3], D[i - 4]�� �ϳ��� 0�� ��� ����̰� �̱��
        �׷��� ���� ��� â���̰� �̱��.
    */
    for (int i = 5; i <= n; i++) {
        if (D[i - 1] == 0 || D[i - 3] == 0 || D[i - 4] == 0)
            D[i] = 1; 
        else 
            D[i] = 0;
    }

    if(D[n] == 1)
        cout << "SK";
    else
        cout << "CY";
}