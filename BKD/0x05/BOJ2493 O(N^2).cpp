#include<bits/stdc++.h>
using namespace std;

int arr1[500005];
int arr2[500005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    for(int i = n - 1; i > 0; i--){
        for(int j = i - 1; j > 0; j--){
            if(arr1[j] - arr1[i] >= 0){
                arr2[i] = j+1;
                break;
            }
            else{
                arr2[i] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr2[i] << ' ';
    }
}