#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            if(lost[i] == reserve[j]){
                answer++;
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                // erase �� ��� lost.size()�� ������Ʈ �������� 
                // i�� ����Ű�� �ε����� �״�� �̹Ƿ� ������ �ε����� ����Ŵ
                // for���� ������ i++�� �ϹǷ� -1���� �ʱ�ȭ ���־�� 0���� ������
                // j�� break�� �ɸ��� �ٽ� 0���� �����ϹǷ� �������
                i = -1; 
                break;
            }
        }
    }

    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            if(lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1){
                answer++;
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }

    return answer;
}