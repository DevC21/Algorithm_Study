#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int len = citations.size();
    
    // H-Index�� citations�� ũ�⸦ �����ʴ´�.
    for(int i = 0; i < len; i++){
        // citations[i]�� �̻� �ο�� ���� citations[i]�� �̻����� �˻�
        if(len - i >= citations[i])
            answer = max(citations[i], answer);
        // citations[i]�� �̻� �ο�� ���� citations[i]�� �̸��̶�� 
        // ���� ���� ������ H-index�� ��
        else{ 
            answer = max(len - i, answer);
            break;
        }
    }

    return answer;
}