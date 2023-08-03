#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    // �������� ����
    sort(people.begin(), people.end());

    int start = 0;
    int end = people.size() - 1;

    while(start <= end){
        // start�� end�� ���ٴ� ���� ȥ�� ���Ҵٴ� ���̴�.
        // answer�� 1�� �����ְ� while ���� ����������.
        if(start == end){
            answer++;
            break;
        }
        // �����ִ� ����߿� ���� ������ ����� ���� ���ſ� ����� ���� ���ѿ� �ɸ��� ������
        // �� ����� Ÿ�� ���� �� �ִ�.
        else if(people[start] + people[end] <= limit){
            start++;
            end--;
            answer++;
        }
        // �����ִ� ����߿� ���� ������ ����� ���� ���ſ� ����� ���� ������ ������
        // ���� ���ſ� ����� ������ ȥ�ڼ� Ÿ�� ������ �Ѵ�.
        else if(people[start] + people[end] > limit){
            end--;
            answer++;
        }
    }

    return answer;
}