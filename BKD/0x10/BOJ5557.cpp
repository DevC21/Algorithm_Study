#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// BOJ1495 ��Ÿ����Ʈ�� ����� ����

int n;
int arr[105];
// i + 1��° ���ʿ� +, - �������� ���� j�� ���� �� �ִ� ����� ��
ll D[105][21];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // ù��°�� arr[0]�� ���� ����� ���� �ϳ����̴�.
    D[0][arr[0]] = 1;

    //n - 2��°������ ����ո� �ʿ� �ϹǷ� i < n - 1
    for(int i = 1; i < n - 1; i++){
        for(int j = 0; j <= 20; j++){
            // D[i - 1][j]�� 0�̸� �������� �־��� ���ڷδ� j�� ���� �� ���ٴ� ��
            if(D[i - 1][j] == 0)
                continue;

            // +, - ����
            int plus = j + arr[i];
            int minus = j - arr[i];

            // +, - ������ ����� 0 �̻� 20 ���϶��
            // i - 1��°�� j�� ���� �� �ִ� ����� ����
            // i��°�� +, - ������ ����� ���� �� �ִ� ����� ���̴�.
            if(plus <= 20)
                D[i][plus] += D[i - 1][j];
            if(minus >= 0)
                D[i][minus] += D[i - 1][j];
        }
    }

    // n - 2��°������ ������� n - 1��° ���ڰ� �Ǿ��Ѵ�.
    cout << D[n - 2][arr[n - 1]];
}