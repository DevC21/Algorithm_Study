#include<bits/stdc++.h>
using namespace std;

set<int> s;
int elements_size;

void func(int len, const vector<int> &elements){
    // 0�� �ε������� elements_size - 1 �ε������� �ݺ�
    for(int i = 0; i < elements_size; i++){
        int sum = 0;
        // i�� �ε������� �����ϴ� len ������ ���� �κ� ������ ���� ����
        // elements�� ���� ������ 2�� �� �ֱ� ������
        // j�� elements_size���� ũ���� ���� ������ �����ϴ� ��ó�� ������
        for(int j = i; j < i + len; j++)
            sum += elements[j];

        // set�� ���� ���� �־� �ߺ� ����
        s.insert(sum);
    }
}

int solution(vector<int> elements){
    int answer = 0;

    // ���� ������ ����� �� ���� ���̸� ���
    elements_size = elements.size();
    
    // ���� ������ ����� ���� elements ������ �ѹ� �� �־���
    for(int i = 0; i < elements_size; i++)
        elements.push_back(elements[i]);

    // ���� 1���� ������ ���̸�ŭ �ݺ�
    for(int i = 1; i <= elements_size; i++)
        func(i, elements);

    answer = s.size();
    return answer;
}