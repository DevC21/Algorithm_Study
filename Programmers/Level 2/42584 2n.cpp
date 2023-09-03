#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int arr[100'005];
    // �ֽ��� �� �ð� / ����
    stack<pair<int, int>> s;

    for(int i = 0; i < prices.size(); i++){
        if(!s.empty()){
            // ������ �� ���� ������ ���� ���ݺ��� ��θ� �ֽ��� ������ ���̹Ƿ�
            // ���� ���ݺ��� �ΰų� ���� ������ ���ö����� pop�Ѵ�.
            while(!s.empty() && s.top().second > prices[i]){
                // �ֽ��� �� ������ �� �� ���� �������� �ʾҴ��� ���
                // i(����ð�) - s.top().first(������ �ð�)
                arr[s.top().first] = i - s.top().first;
                s.pop();
            }
        }
        s.push({i, prices[i]});
    }

    // �� ������ ��� ��ġ�� ������ ��� ���� �ʴٸ�
    // ���ÿ� �����ִ� �ֽ��� ��� ������ ������ �������� ���� �ֽ��̹Ƿ�
    // ��ü �ð�(prices.size()) - s.top().first(������ �ð�) - 1�� ��� ���ش�.
    if(!s.empty()){
        while(!s.empty()){
            arr[s.top().first] = prices.size() - s.top().first - 1;
            s.pop();
        }
    }

    for(int i = 0; i < prices.size(); i++)
        answer.push_back(arr[i]);

    return answer;
}