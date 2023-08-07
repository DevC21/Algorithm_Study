#include<bits/stdc++.h>
using namespace std;

map<int, int> tangerine_size;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    vector<int> sizes;
    int sum = 0;

    // ����� ���� ����
    for(auto x : tangerine)
        tangerine_size[x]++;

    // ����� ������ �����ϱ� ���� ���Ϳ� ����
    for(auto x : tangerine_size)
        sizes.push_back(x.second);

    // �������� ����
    sort(sizes.rbegin(), sizes.rend());

    // ���� ���� ��������� �ϳ��� ���� �߰�
    // k���� ������ �������� break
    for(int i = 0;  i <= sizes.size(); i++){
        sum += sizes[i];
        answer++;
        if(sum >= k)
            break;
    }

    return answer;
}