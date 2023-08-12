#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// ���� �ؼ� : https://maloveforme.tistory.com/38

vector<int> solution(int n, ll left, ll right) {
    vector<int> answer;

    // �迭�� ���� ��Ģ�� ���� �����Ǵ� (x, y)���� x�� y �� ū ���� �ȴ�
    // x�� ���� i / n
    // y�� ���� i % n
    // �迭�� (1,1)���� �����ϱ⶧���� + 1
    for(ll i = left; i <= right; i++)
        answer.push_back(max(i / n, i % n) + 1);

    return answer;
}