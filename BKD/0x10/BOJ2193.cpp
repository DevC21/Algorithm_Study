#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// ���� i�� ������ �� ���� 0�̰ų� 1�̴�.
// 0�� ������ ������ �ڸ��� ä��� ����� ���� f(i - 1)���� �ִ�.
// 1�� ������ �ڿ��� �� ��° ���� 0�� �Ǿ�� �ϹǷ� ���� 2���� �����Ǿ� f(i - 2)���� �ִ�.
// ���� f(i) = f(i - 1) + f(i - 2)�� �����ϸ� �Ǻ���ġ �����̴�.

int n;
ll D[91];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[1] = 1;
    D[2] = 1;

    for(int i = 3; i <= n; i++)
        D[i] = D[i - 1] + D[i - 2];

    cout << D[n];
}