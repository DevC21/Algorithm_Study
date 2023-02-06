#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[20];
    int a,b;

    for(int i = 0; i < 20; i++){
        arr[i] = i+1;
    }

    for(int i = 0; i < 10; i++){
        cin >> a >> b;
        for(int j = 0; j < b - a; j++){
            for(int k = 0; k < b - a - j; k++){
                int tmp = arr[k+a-1];
                arr[k+a-1] = arr[k+a];
                arr[k+a] = tmp;
            }
        }
    }

    for(int i = 0; i < 20; i++){
        cout << arr[i] << ' ';
    }
}