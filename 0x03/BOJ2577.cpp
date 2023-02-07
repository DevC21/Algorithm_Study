#include<bits/stdc++.h>
using namespace std;

int idx[10];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    int i = 10;
    cin >> a >> b >> c;

    int Multi = a*b*c; 
    while ( i <= Multi){
        i *= 10;
    }
    i /= 10;

    while(i > 0){
        int j = Multi / i;
        idx[j]++;
        Multi %= i;
        i /= 10;
    }

    for(int i = 0; i < 10; i++){
        cout << idx[i] << '\n';
    }
}