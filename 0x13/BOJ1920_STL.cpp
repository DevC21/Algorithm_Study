#include<bits/stdc++.h>
using namespace std;

int A[100005];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort(A, A+n);

    int m;
    cin >>m;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        cout << binary_search(A, A+n, t) << '\n';
    }
}