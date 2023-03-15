#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[1005];
ll ans;

// �Ź� �ּ��� �� ���Ҹ� O(N)�� ã�� �׸��� Ǯ��
// �켱���� ť�� �̿��� O(lg N)�� Ž�� ������ Ǯ�̰� ����
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    for(int i = 0; i < m; i++){
        ll sum = a[0] + a[1];
        a[0] = sum;
        a[1] = sum;
        sort(a, a+n);
    }

    for(int i = 0; i < n; i++){
        ans += a[i];
    }

    cout << ans;
}