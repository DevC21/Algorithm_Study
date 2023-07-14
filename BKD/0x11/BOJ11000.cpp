#include<bits/stdc++.h>
using namespace std;

int n, ans;
pair<int, int> lecture[200'005];
priority_queue<int, vector<int>, greater<>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> lecture[i].first >> lecture[i].second;

    // ���� �ð� �������� ���� ����
    sort(lecture, lecture+n);

    // ù ��° ������ ���� �ð��� pq �� ����
    pq.push(lecture[0].second);

    for(int i = 1; i < n; i++){
        // i ��° ������ ���� �ð��� pq �� ����
        pq.push(lecture[i].second);
        // top�� ���� �ð����� i ��° ������ �ʰ� �����Ѵٸ�, ���� ���ǽǿ��� ���� ����
        if (pq.top() <= lecture[i].first)
            // ���� top�� pop
            pq.pop();
    }

    // pq�� ���� ������ ������ �ʿ��� ���ǽ� �����̴�.
    cout << pq.size();
}