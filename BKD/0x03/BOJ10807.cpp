#include<bits/stdc++.h>
using namespace std;

int arr[105];
int Negidx[105];
int idx[105];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, v;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] >= 0){
            idx[arr[i]]++;
        }
        else if(arr[i] < 0){
            Negidx[arr[i]*-1]++;
        }
    }

    cin >> v;

    if( v >= 0){
        cout << idx[v];
    }
    else if( v < 0){
        cout << Negidx[v*-1]++;
    }

}