#include<bits/stdc++.h>
using namespace std;

int n;
int D[31];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[0] = 1;
    // n�� Ȧ�� �� ��� 2��1, 1��2 ũ���� Ÿ�Ϸ� ������ ��ĭ�� ä��°� �Ұ����ϴ�.
    D[1] = 0;
    D[2] = 3;

    for(int i = 4; i <= n; i += 2){
        // 3 x n ũ���� ���� 3 x (n - 2) + 3 x 2�� ä��� ���
        D[i] = D[i - 2] * D[2];
        // �� ���̽��� �ߺ����� �ʱ� ���ؼ� 3 x 4���� �߻��ϴ� Ư���� ����(2��)��
        // ������ Ÿ�Ͽ� ����� ������ �����ش�.
        for(int j = i - 4; j >= 0; j -= 2)
            D[i] += D[j] * 2;
    }

    cout << D[n];
}