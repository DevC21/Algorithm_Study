#include<bits/stdc++.h>
using namespace std;

// ���� �빮�� ���ĺ� 26���� ȹ���� �̸� ����
int c[] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
string A, B;
vector<int> D;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    cin >> A >> B;

    // �Է� ���� ���ڿ� 'A' ���� ���ָ� 
    // int c �迭���� �� ���ĺ��� ȹ���� �̾� �� �� ����
    for(int i = 0; i < A.size(); i++){
        // A, B�� ���� �ε����� ������� D�� push_back�ϸ�
        // �� ���ھ� ������ ����� �� ó�� push��
        D.push_back(c[A[i] - 'A']);
        D.push_back(c[B[i] - 'A']);
    }

    while(true){
        vector<int> tmp;
        // �� ���� ���
        for (int i = 0; i < D.size() - 1; i++)
            tmp.push_back((D[i] + D[i + 1]) % 10);
        // D�� ���� ������ �ٲ���
        D = tmp;
        // D�� ���Ұ� 2���� ���Ҵٸ� ����� ����
        if (D.size() == 2) {
            cout << D[0] << D[1] << '\n';
            return 0;
        }
    }
}