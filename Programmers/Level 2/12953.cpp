#include<bits/stdc++.h>
using namespace std;

// ��Ŭ���� ȣ������ �̿��� �ּҰ���� ���ϱ�
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

/*
n���� �ּҰ����
A�� B�� �ּҰ���� = x
x�� C�� �ּҰ���� = y
y�� D�� �ּҰ���� = z
A, B, C, D�� �ּҰ������ 'z'�� �ȴ�
*/

int solution(vector<int> arr) {
    int answer = 0;

    answer = lcm(arr[0], arr[1]);

    for(int i = 2; i < arr.size(); i++)
        answer = lcm(answer, arr[i]);

    return answer;
}