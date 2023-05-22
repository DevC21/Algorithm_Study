#include<bits/stdc++.h>
using namespace std;

int male[7];
int female[7];

int main(void){
    ios::sync_with_stdio(0);

    int n, k, s, y;
    int room = 0;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> s >> y;
        if(s == 0){
            female[y]++;
        }
        else{
            male[y]++;
        }
    }

    for(int i = 1; i < 7; i++){
        if( (male[i] % k) == 0){
            room += male[i] / k;
        }
        else{
            room += (male[i] / k) + 1;
        }
        
        if( (female[i] % k) == 0){        
            room += female[i] / k;
        }
        else{
            room += (female[i] / k) + 1;
        }
    }

    cout << room;
}