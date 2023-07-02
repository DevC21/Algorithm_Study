#include<bits/stdc++.h>
using namespace std;

// 11726�� 2xn Ÿ�ϸ��� ���� �Ǻ���ġ �� ����
/*
N-2�� ����� ���鿣 "�� �ڿ�" 00�� ���̰�, 
N-1�� ����� ���鿣 "�� �տ�" 1�� �ٿ�����
N = 5�϶�
N-2�� �� �ڿ� 00�߰� -> 00100,10000,11100
N-1�� �� �տ� 1 �߰�-> 10011,10000,11001,1100,11111
*/

int n;
int D[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[1] = 1;
    D[2] = 2;

    if(n == 1){
        cout << 1;
        return 0;
    }
    else if(n == 2){
        cout << 2;
        return 0;
    }

    for(int i = 3; i <=n; i++){
        D[i] = (D[i-2] + D[i-1])% 15746;
    }

    cout << D[n] % 15746;
}