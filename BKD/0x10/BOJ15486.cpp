#include<bits/stdc++.h>
using namespace std;

int t[1'500'005];
int p[1'500'005];
int D[1'500'005]; // i��° �Ͽ� ����� �������� �� ���� �� �ִ� �ִ� ����

// ������ ������ ���� �ܼ��� n�� ũ�⸸ Ŀ�� ����

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    for (int i = n; i >= 1; i--) {
        // i��° �Ͽ� ����� �� �� ���� ���
        // == i�� + ��㿡 �ɸ��� �Ⱓ t[i]�� ������� n + 1�� ���� �ʴ� ���
        if (i + t[i] <= n + 1) {
            // i��° �Ͽ� ����� ���� ���� ����� ���� �ʾ��� �� ���� �� �ִ� ���� �� �ִ� ������ ����
            D[i] = max(D[i + t[i]] + p[i], D[i + 1]);
        }
        else D[i] = D[i + 1];
    }
  cout << *max_element(D, D + n + 1);
}