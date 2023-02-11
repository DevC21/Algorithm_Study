#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<pair<int, int>> DQ;
    int n, l;

    cin >> n >> l;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        // ���ο� ���ڰ� deque������ ���� ū ���� �����̰� �������� ��ġ�ϵ��� �մϴ�.
        // deque������ ���ڵ��� �������� ���¸� �����ϰ� �ǰ�, ������ ���� �������� �׻� �Ǿ�(front)�� �ִ� ���¸� ������ �˴ϴ�.
        while (!DQ.empty() && DQ.back().second >= num) {
            DQ.pop_back();
        }

        // ���ο� ���ڴ� �׻� ���Ե˴ϴ�.
        DQ.push_back({i, num});

        // �־��� ������ ����� outdate�� ���ڵ��� �������ݴϴ�.
        if (DQ.front().first <= i - l) {
            DQ.pop_front();
        }

        cout << DQ.front().second << " ";
    }


}