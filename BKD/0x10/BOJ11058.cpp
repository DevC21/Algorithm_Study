#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, v = 3;
ll D[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[1] = 1;
    D[2] = 2;
    D[3] = 3;
    D[4] = 4;
    D[5] = 5;
    D[6] = 6;

    // D[i]�� �ִ밪�� ���� 3���� ��찡 �����ϴ�.
    // 1. Ctrl + A, Ctrl + C�� 2�ܰ踦 ���� ����, Ctrl + V�� �� �� �ٿ��ֱ��� D[i - 3] + D[i - 3] * 1
    // 2. ���� �ܰ踦 ���� ����, Ctrl + V, Ctrl + V�� �� �� �ٿ��ֱ��� D[i - 4] + D[i - 4] * 2
    // 3. ���� �ܰ踦 ���� ����, �� �� �ٿ��ֱ��� D[i - 5] + D[i - 5] * 3
    for(int i = 7; i <= n; i++)
        for(int j = 3; j <= 5; j++)
            D[i] = max(D[i], D[i - j] * (j - 1));

    cout << D[n];
}