#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int arr[3][4];

    for(int i = 0; i < 3 ; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    for(int i = 0; i < 3 ; i++){
        int count = 0;
        for(int j = 0; j < 4; j++){
            if(arr[i][j] == 1)
                count++;
        }
        if(count == 0){
            cout << "D\n";
        }
        else if(count == 1){
            cout << "C\n";
        }
        else if(count == 2){
            cout << "B\n";
        }
        else if(count == 3){
            cout << "A\n";
        }
        else if(count == 4){
            cout << "E\n";
        }
    }
}