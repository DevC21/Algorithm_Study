#include<bits/stdc++.h>
using namespace std;

int arrA[20005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        int n, m;
        int cnt = 0;
        cin >> n >> m;
        for(int j = 0; j < n; j++){
            cin >> arrA[j];
        }
        sort(arrA, arrA+n);

        for(int j = 0; j < m; j++){
            int num;
            cin >> num;
            int idx = upper_bound(arrA, arrA+n, num) - arrA;
            cnt += n - idx;
        }
        cout << cnt << '\n';
    }
}