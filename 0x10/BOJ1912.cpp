#include<bits/stdc++.h>
using namespace std;

int arr[100005];
int D[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int maxval = arr[0];
    D[0] = arr[0];
 
    for(int i = 1; i < n; i++){
        D[i] = max(D[i-1] + arr[i], arr[i]);

        maxval = max(D[i], maxval);
    }
    
    cout << maxval;
}