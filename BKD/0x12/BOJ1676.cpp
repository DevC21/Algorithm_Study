#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int div5;
int div25;
int div125;

// 5�� ����� ������ ����, �װ��� �ڵ������� 10�� ����� ������ �ȴ�
// 5�� ������ 25�� ����� 5�� �ΰ��̹Ƿ�, 10�� ����� �ѹ��� �ΰ��� ��Ÿ���� ��
// �������� 125�� ����� 5�� �����̹Ƿ�, 10�� ����� �ѹ��� ������ ��Ÿ���� ��
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    div5 = n / 5;
    div25 = n / 25;
    div125 = n / 125;

    cout << div5 + div25 + div125;
}