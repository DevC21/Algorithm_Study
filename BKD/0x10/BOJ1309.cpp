#include<bits/stdc++.h>
using namespace std;

int n;
// 2*N �迭�� ���ڸ� ��ġ�ϴ� ����� ��
// D[i][0] = ù ��ĭ�� �����϶�
// D[i][1] = ù ��ĭ�� �¿쿡 �Ѹ����� ��ġ�� ��� 
// ���� : D[i][2] ���� ���� �� ������ ����, ���� ��� ���� ����� ���� �����Ƿ� * 2 ������ �� �� ����
int D[100'005][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[1][0] = 1;
    D[1][1] = 1 * 2; // ù ��ĭ�� �¿쿡 ��ġ�� ����Ǽ� 1 * 2

    for(int i = 2; i <= n; i++){
        D[i][0] = (D[i - 1][0] + D[i - 1][1]) % 9901 ;
        D[i][1] = (D[i - 1][0] * 2 + D[i - 1][1]) % 9901;
    }

    cout << (D[n][0] + D[n][1]) % 9901 << '\n';
}