#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<>> pq;
    int n, ans = 0;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        pq.push(c);
    }

    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a+b);
    }

    cout << ans;
}