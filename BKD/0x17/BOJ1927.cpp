#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    unsigned int t;
    priority_queue<unsigned int, vector<unsigned int>, greater<>> pq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t)
        pq.push(t);
        else {
            if (pq.empty())
                cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}