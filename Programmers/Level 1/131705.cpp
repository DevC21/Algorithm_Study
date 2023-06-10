#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
int answer = 0;
int n;

void DFS(vector<int> &number, int sum, int cur, int idx){
    if(cur == 3){
        if(sum == 0)
            answer++;
        return;
    }

    for(int i = idx; i < n; i++)
        DFS(number, sum + number[i], cur + 1, i + 1);
}

int solution(vector<int> number) {
    n = number.size();
    // number = �Է����� �־��� number ����
    // number[i] = ������ ���� ������ ��
    // 1 = ���� �� ���� (1��)
    // i + 1 = i���� 1 ū �ε������� DFS�� ����
    //         (���� ���Ҹ� �ٽ� ���� �ʱ�����)
    for(int i = 0; i < n; i++)
        DFS(number, number[i], 1, i + 1);

    return answer;
}