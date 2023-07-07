#include<bits/stdc++.h>
using namespace std;

int n, m, ans;
int arr[1005][1005];
int D[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        s = '0' + s;
        for(int j = 1; j <= m; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] == 1){
                // ���� �� �밢��, ����, ������ üũ�ϰ� �� �� ���� ���� ���� + 1�� �Ѵ�
                D[i][j] = min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]}) + 1;
                ans = max(D[i][j], ans);
            }
        }
    }

    cout << ans * ans;
}