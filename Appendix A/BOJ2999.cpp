#include<bits/stdc++.h>
using namespace std;

char arr[105][105];

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    int r, c;
    string msg;
    cin >> msg;

    int strsize = msg.size();
    for(int i = 1; i < strsize; i++){
        if(strsize % i == 0){
            if(i > (strsize / i))
                break;
            r = i;
            c = strsize / i;
        }
    }

    int idx = 0;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            arr[i][j] = msg[idx];
            idx++;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << arr[j][i];
        }
    }
}