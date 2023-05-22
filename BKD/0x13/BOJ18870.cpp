#include<bits/stdc++.h>
using namespace std;

int A[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector <int> sortv;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        A[i] = x;
        sortv.push_back(x);
    }

    sort(sortv.begin(), sortv.end());

    sortv.erase(unique(sortv.begin(), sortv.end()), sortv.end());

    for(int i = 0; i < n; i++){
        cout << lower_bound(sortv.begin(), sortv.end(), A[i]) - sortv.begin() << ' ';
    }
}