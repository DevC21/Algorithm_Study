#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[5];
    int avg = 0;

    for(int i = 0; i < 5; i++){
        cin >> arr[i];
        avg += arr[i];
    }
    avg /= 5;

    cout << avg << '\n';


    for(int i = 0; i < 5; i++){
        int tmp = arr[i];
        for(int j = 0; j < 5; j++){
            if(arr[i] < arr[j]){
                arr[i] = arr[j];
                arr[j] = tmp;
                tmp = arr[i];
            }
        }
    }

    cout << arr[2];
}