#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[2005];
int D[2005][2005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 1; i <= n; i++){
        D[i][i] = 1;
        if(arr[i - 1] == arr[i])
            D[i - 1][i] = 1;
    }
        
    // �� �������� �̹� ���̰� 1, 2�� ��츦 ��������Ƿ� 
    // ���̰� j + i = 3 ������ ����Ѵ�.
    for(int i = 2; i < n; i++){
        for(int j = 1; j <= n - i; j++){
            int s = j;
            int e = j + i;
            // ���� ��(s, e)�� ���� �� ���̿� �ִ� ����
            // �� s + 1��° ���ڿ� e - 1��° ���ڰ� �Ӹ�����̶�� 
            // D[s][e]�� �Ӹ�����̴�.
            if(arr[s] == arr[e] && D[s + 1][e - 1]) 
                D[s][e] = 1;
        }
    }

    cin >> m;
    while(m--){
        int s, e;
        cin >> s >> e;
        cout << D[s][e] << '\n';
    }
}