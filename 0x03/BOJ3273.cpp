#include<bits/stdc++.h>
using namespace std;

int arr[1000005];
int intarr[2000005];

int main(void){
    int n, x;
    int cnt = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> x;

    for(int i = 0; i < n; i++){
        if(x-arr[i] < 0)
            continue;
        if(intarr[x-arr[i]])
            cnt++;
        intarr[arr[i]] = 1;
    }
    
    cout << cnt;
}