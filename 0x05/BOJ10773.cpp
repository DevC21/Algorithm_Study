#include<bits/stdc++.h>
using namespace std;

int main(void){
    stack<int> S;

    int k, n;
    int sum = 0;

    cin >> k;

    for(int i = 0; i < k; i++){
        cin >> n;
        if( n > 0){
            S.push(n);
            sum += n;
        }
        else if( n == 0){
            sum -= S.top();
            S.pop();
        }
    }

    cout << sum;
}