#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int five = n / 5;
    int two = (n % 5) / 2;
    if(five * 5 + two * 2 == n){
        cout << five + two;
    }
    else{
        five = n / 5 - 1;
        if(five < 0){
            two = n / 2;
            five = 0;
        }
        else{
            two = (n % 5 + 5) / 2;
        }
        
        if(five * 5 + two * 2 == n)
            cout << five + two;
        else
            cout << -1;
    }
}