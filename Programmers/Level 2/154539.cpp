#include<bits/stdc++.h>
using namespace std;

// BOJ17298 ��ū���� �Ȱ��� ����
// �ٸ� answer�� 0��° �ε������� ������� ��ū���� ���� �ϹǷ�
// answer�� �ѹ� �����������

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> s;

    for(int i = numbers.size() - 1; i >= 0; i--){
        while(!s.empty()){
            if(s.top() > numbers[i])
                break;
            s.pop();
        }
        
        if(s.empty()) answer.push_back(-1);
        else answer.push_back(s.top());

        s.push(numbers[i]);
    }

    reverse(answer.begin(), answer.end());
    return answer;
}