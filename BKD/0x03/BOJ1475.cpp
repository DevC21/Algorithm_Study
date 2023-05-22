#include<bits/stdc++.h>
using namespace std;

int idx[10];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int i = 10;
    int max = 0;

    cin >> n;

    while ( i <= n){
        i *= 10;
    }
    i /= 10;

    while(i > 0){
        int j = n / i;
        idx[j]++;
        n %= i;
        i /= 10;
    }

    for(int i = 0; i < 10; i++){
        if(max < idx[i]){
            if( i == 6 || i == 9){
                if((idx[6] + idx[9]) % 2 == 0){
                    max = (idx[6] + idx[9]) / 2;
                }
                else{
                    max = (idx[6] + idx[9]) / 2 + 1;
                }
            }
            else
            {
                max = idx[i];
            }
        }
    }
    
    cout << max;
}