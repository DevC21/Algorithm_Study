#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9], sort[7];
    int total = 0;
    int count = 0;

    for(int i = 0; i < 9; i++){
        cin >> arr[i];
        total += arr[i];
    }

    for(int i = 0; i < 9; i++){
        int tmp = arr[i];
        for(int j = 0; j < 9; j++){
            if(arr[i] < arr[j]){
                arr[i] = arr[j];
                arr[j] = tmp;
                tmp = arr[i];
            }
        }
    }

    for(int i = 0; i < 8; i++){
        count = 0;
        for(int j = i + 1; j < 9; j++){
            if ( total - arr[i] - arr[j] == 100){
                for(int k = 0; k < 9; k++){
                    if(k == i || k == j)
                        continue;
                    sort[count] = arr[k];
                    count++;
                }
            }
        }
    }

    for(int i = 0; i < 7; i++){
        cout << sort[i] << '\n';
    }
}