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

    // 시작 시간 기준으로 강의 정렬
    sort(lecture, lecture+n);

    // 첫 번째 강의의 종료 시간을 pq 에 삽입
    pq.push(lecture[0].second);

    for(int i = 1; i < n; i++){
        // i 번째 강의의 종료 시간을 pq 에 삽입
        pq.push(lecture[i].second);
        // top의 종료 시간보다 i 번째 수업이 늦게 시작한다면, 같은 강의실에서 진행 가능
        if (pq.top() <= lecture[i].first)
            // 기존 top은 pop
            pq.pop();
    }

    // pq에 남은 강의의 개수가 필요한 강의실 개수이다.
    cout << pq.size();
}