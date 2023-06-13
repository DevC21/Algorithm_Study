#include<bits/stdc++.h>
using namespace std;

//�ؼ� �� ���� ���� ����Ʈ : https://readable-ko.site/168
int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int maxlen = 0;
    int minlen = 0;
    for(int i = 0; i < sizes.size(); i++){
        // w�� �� ������ ���� �� �� ������
        // h�� �� ������ ���� �� ª�� ������
        int w = max(sizes[i][0], sizes[i][1]);
        int h = min(sizes[i][0], sizes[i][1]);

        // �� ���� �ְ� ��, ª�� ���� �ְ� ��
        maxlen = max(w, maxlen);
        minlen = max(h, minlen);
    }

    answer = maxlen * minlen;
    return answer;
}