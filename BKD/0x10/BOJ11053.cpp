#include<bits/stdc++.h>
using namespace std;

int arr[1005];
int D[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int maxlen = 1;
    D[0] = 1;

    for(int i = 1; i < n; i++){
        D[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && D[i] <= D[j])
                D[i] = D[j] + 1;
        }

        maxlen = max(maxlen, D[i]);
    }

    cout << maxlen;
}