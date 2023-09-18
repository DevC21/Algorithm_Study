#include<bits/stdc++.h>
using namespace std;

int arr[1005][1005];

vector<int> solution(int n) {
    vector<int> answer;

    // ���� ����
    int x = -1, y = 0;
    int num = 1;

    for (int i = 0; i < n; i++) {
        // �� ������ �ϴ� Ƚ���� 1�� �پ���
        for (int j = i; j < n; j++) {
            // ������ 3���̹Ƿ� i�� 3���� ���� �������� ������ ������ ����
            // ��) i = 0�϶� % 3�� 0�̹Ƿ� �迭�� ���� �������� �����̸� ���� ä���
            if (i % 3 == 0) 
                x++; // ����
            // ��) i = 1�϶� % 3�� 1�̹Ƿ� �迭�� ���� �������� �����̸� ���� ä���                
            else if (i % 3 == 1)
                y++; // ����
            // ��) ��) i = 1�϶� % 3�� 2�̹Ƿ� �迭�� ���� �� �밢�� �������� �����̸� ���� ä���                
            else if (i % 3 == 2) {
                // ���� �� �밢��
                x--;
                y--;
            }
            arr[x][y] = num++;
        }
    }

    // �迭�� �� ���� n + 1���� ������ ������.
    // 0���� 1���� �� 1���� 2���� �� ���������������� n���� n + 1���� ��
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);

    return answer;
}