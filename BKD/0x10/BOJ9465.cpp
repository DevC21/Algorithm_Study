#include<bits/stdc++.h>
using namespace std;

int n, t;
int arr[2][100001];
int D[2][100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){
        cin >> n;

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        // D[0][0] ���� ������ ��� 
        D[0][0] = arr[0][0];
        // D[1][0]���� ������ ���
        D[1][0] = arr[1][0];
        D[0][1] = arr[0][1] + D[1][0];
        D[1][1] = arr[1][1] + D[0][0];

        for (int i = 2; i < n; i++) {
            // ��ĭ �� �밢���� ��ƼĿ or ��ĭ �� �밢���� ��ƼĿ�� �� �� �� �� ū ���� ����
            D[0][i] = arr[0][i] + max(D[1][i - 1], D[1][i - 2]);
            D[1][i] = arr[1][i] + max(D[0][i - 1], D[0][i - 2]);
        }
    
        cout << max(D[0][n - 1], D[1][n - 1]) << '\n';
    }
}