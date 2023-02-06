#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int callnum, calllen[21];
    int Ytotal = 0;
    int Mtotal = 0;

    cin >> callnum;
    
    for(int i = 0; i < callnum; i++){
        cin >> calllen[i];
    }

    for(int i = 0; i < callnum; i++){
        Ytotal += (calllen[i]/30 + 1) * 10;
        Mtotal += (calllen[i]/60 + 1) * 15;
    }

    if(Mtotal == Ytotal){
        cout << 'Y' << ' ' << 'M' << ' ' << Ytotal;
    }
    else if(Mtotal < Ytotal){
        cout << 'M' << ' ' << Mtotal;
    }
    else if(Ytotal < Mtotal){
        cout << 'Y' << ' ' << Ytotal;
    }
}