#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n[11], index, max;
    index = 0;
    max = 0;


    for(int i = 0; i < 9; i++){
        cin >> n[i];
        if(n[i] > max){
            max = n[i];
            index = i+1;
        }
    }

    cout << max << '\n' << index;
}