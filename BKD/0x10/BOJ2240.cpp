#include<bits/stdc++.h>
using namespace std;

int t, w, ans = 0;
int D[2][31][1001];
int arr[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> t >> w;

	for (int i = 1; i <= t; i++)
		cin >> arr[i];

	for (int j = 0; j <= w; j++){
		for (int i = 1; i <= t; i++){
			if (j == 0){
                //j == 0�϶��� 1�� ������ ��ġ��
                if(arr[i] == 1)
				    D[0][j][i] = D[0][j][i - 1] + 1;
                else
                    D[0][j][i] = D[0][j][i - 1];
			}
			else{
				//j > 0 �϶�, ��ġ ������or�ȿ�����, ����or�������� Ȯ��
                if(arr[i] == 1){
                    D[0][j][i] = max(D[0][j][i - 1] + 1, D[1][j - 1][i - 1] + 1);
                    D[1][j][i] = max(D[1][j][i - 1], D[0][j - 1][i - 1]);
                }
                else{
                    D[0][j][i] = max(D[0][j][i - 1], D[1][j - 1][i - 1]);
                    D[1][j][i] = max(D[1][j][i - 1] + 1, D[0][j - 1][i - 1] + 1);
                }
				// D[���� ��ġ][�̵�Ƚ��][�帥 �ð�] = 
				// (�̵������ʰ� �ð��� 1�� �帧 + i��° �Է°� ���� ��ġ�� ������?), 
				// (�̵��߰�, 1�� �帧 + i��° �Է°� ���� ��ġ�� ������?) �� ū ��
			}
		}
	}

	for (int i = 0; i < 2; i++){
		for (int j = 0; j <= w; j++){
        	// �������� ������ ��� �̵�Ƚ��(j)��, ��ġ(1, 2)�� ���� ū ���� ����Ѵ�.
			ans = max(ans, D[i][j][t]);
		}
	}

    cout << ans;
}