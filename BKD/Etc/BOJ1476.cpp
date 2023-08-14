#include<bits/stdc++.h>
using namespace std;

int esm[3];
int e, s, m;
int year;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 3; i++)
        cin >> esm[i];

    e = 1;
    s = 1;
    m = 1;
    year = 1;
    while(true){
        if(e == esm[0] && s == esm[1] && m == esm[2])
            break;

        e = e % 15 + 1;
        s = s % 28 + 1;
        m = m % 19 + 1;
        year++;
    }

    cout << year;
}