#include<bits/stdc++.h>
using namespace std;

// ���� �ؼ� ���� : https://www.crocus.co.kr/787

string a, b, LCS;
int D[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    a = "0" + a;
    b = "0" + b;

    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            // �� ���ڰ� ���� ���
            if(a[i] == b[j])
                // �밢���� ���� �����Ͽ� LCS�� ���� + 1 �Ѵ�.
                D[i][j] = D[i - 1][j - 1] + 1;
            // �� ���ڰ� �ٸ� ���
            else
                // �� ���ڿ��� ���� ���� �� �ִ� LCS���� ����.
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
        }
    }

    int i = a.size() - 1;
    int j = b.size() - 1;
    while (D[i][j] != 0){
        /*
            �� ������� - ���̺��� ���� �� �ߴ� �۾��� �ݴ�� �����Ѵ�.
            D[a.size() - 1][b.size() - 1]���� �����Ͽ� �ڽŰ� ���� ���ڰ� �ִ°����� ���󰣴�.
            �׸��� ����, ���� ���� �Ѵ� ���� ���� ���ٸ�, �밢�� ���� ���� ���� �� - 1���� Ȯ���غ��� �� ���� ���󰣴�.
            �̰��� ���̺��� 0�� ��Ÿ�� �� ���� ����ؼ� �ݺ��Ѵ�.
        */
        if (D[i][j] == D[i][j - 1])
            j--;
        else if (D[i][j] == D[i - 1][j])
            i--;
        else if (D[i][j] - 1 == D[i - 1][j - 1]){
            LCS.insert(LCS.begin(), a[i]);
            i--;
            j--;
        }
    }

    // �������� Ž���� ��ġ�� LCS�� �ִ� ���� ����Ǿ� ���� ���̴�.
    cout << D[a.size() - 1][b.size() - 1] << '\n';
    if(LCS.size() != 0)
        cout << LCS;
}