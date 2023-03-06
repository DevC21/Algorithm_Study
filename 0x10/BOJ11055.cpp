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

    int maxval = arr[0];
    D[0] = arr[0];
 
    for(int i = 1; i < n; i++){
        D[i] = arr[i];
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && D[i] - arr[i] < D[j])
                D[i] = D[j] + arr[i];
        }


        maxval = max(D[i], maxval);
    }
    
    cout << maxval;
}