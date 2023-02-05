#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int oddtotal = 0;
    int min = 100;
    int num[7];

    for(int i = 0; i < 7; i++){
        cin >> num[i];
        if(num[i] % 2 != 0){
            oddtotal += num[i];
            if(num[i] < min)
                min = num[i];
        }
    }

    if(min == 100){
        cout << -1;
    }
    else{
        cout << oddtotal << '\n';
        cout << min;
    }
}