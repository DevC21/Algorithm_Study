#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 최소 힙
    priority_queue<int, vector<int>, greater<>> pq;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            pq.push(num);
        }
        // n번째 큰 수 까지 남긴다
        while (pq.size() > n){
            pq.pop();
        }
    }

    //pq.top() == n번째 큰 수
    cout << pq.top() << '\n';
}
