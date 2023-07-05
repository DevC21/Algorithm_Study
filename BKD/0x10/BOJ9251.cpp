#include<bits/stdc++.h>
using namespace std;

// ���� �ؼ� ���� : https://sskl660.tistory.com/90

string a, b;
int D[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    a = "0" + a;
    b = "0" + b;

    for(int i = 1; i < b.size(); i++){
        for(int j = 1; j < a.size(); j++){
            // �� ���ڰ� ���� ���
            if(b[i] == a[j])
                // �밢���� ���� �����Ͽ� LCS�� ���� + 1 �Ѵ�.
                D[i][j] = D[i - 1][j - 1] + 1;
            // �� ���ڰ� �ٸ� ���
            else
                // �� ���ڿ��� ���� ���� �� �ִ� LCS���� ����.
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
        }
    }
    // �������� Ž���� ��ġ�� LCS�� �ִ� ���� ����Ǿ� ���� ���̴�.
    cout << D[b.size() - 1][a.size() - 1];
}