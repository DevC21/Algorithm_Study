#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int arr[3];

    for(int i = 0 ; i < 3; i++)
        cin >> arr[i];

    for(int i = 0; i < 3; i++){
        int tmp = arr[i];
        for(int j = 0; j < 3; j++){
            if(arr[i] < arr[j]){
                arr[i] = arr[j];
                arr[j] = tmp;
                tmp = arr[i];
            }
        }
    }

    for(int i = 0 ; i < 3; i++)
        cout << arr[i] << ' ';
}