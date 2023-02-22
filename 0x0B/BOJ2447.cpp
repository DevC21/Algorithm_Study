#include<bits/stdc++.h>
using namespace std;

void printstar(int r, int c, int n){
    if((r / n) % 3 == 1 && (c / n) % 3 == 1){
        cout << ' ';
    }
    else{
        if(n / 3 == 0)
            cout <<'*';
        else
            printstar(r, c, n/3);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printstar(i, j, n);
        cout << '\n';
    }
}