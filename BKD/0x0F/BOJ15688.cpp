#include<bits/stdc++.h>
using namespace std;

int Negnumcount[1000001];
int numcount[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp = 0;
        cin >> tmp;
        if(tmp < 0)
            Negnumcount[-tmp]++;
        else
            numcount[tmp]++;
    }

    for(int i = 1000000; i > 0; i--){
        for(int j = 1; j <= Negnumcount[i]; j++){
            cout << -i << '\n';
        }
    }
    for(int i = 0; i < 1000001; i++){
        for(int j = 1; j <= numcount[i]; j++){
            cout << i << '\n';
        }
    }
}