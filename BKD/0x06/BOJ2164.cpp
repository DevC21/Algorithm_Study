#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        Q.push(i+1);
    }

    for(int i = 0; i < n - 1; i++){
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }

    cout << Q.front();
}