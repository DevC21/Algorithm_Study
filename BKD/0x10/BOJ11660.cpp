#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[1030][1030];
int D[1030][1030];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // ���� ��ġ�� ����
            D[i][j] = arr[i][j];
            // ���� ������ ������, ���� ������ �������� ���ϰ�,
            D[i][j] += D[i - 1][j] + D[i][j - 1];
            // i - 1�� j - 1���� �������� ���ش�. (�ߺ����� ���߱⶧����)
            D[i][j] -= D[i - 1][j - 1];
        }
    }

    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        //arr[1][1] ~ arr[x2][y2]�� �κ���(��ü �簢��)����
        int ans = D[x2][y2];
        //arr[1][1] ~ arr[x2][y1 - 1]�� �κ���(���� �簢���� ���� �κ�)��
        ans -= D[x2][y1 - 1];
        //arr[1][1] ~ arr[x1 - 1][y2]�� �κ���(���� �簢���� ���� �κ�)�� ����
        ans -= D[x1 - 1][y2];
        //arr[1][1] ~ arr[x1 - 1][y1 - 1]�� �κ���(�� �� �簢���� ��ġ�� �κ�)�� ���Ѵ�.
        ans += D[x1 - 1][y1 - 1];

        cout << ans << '\n';
    }
}