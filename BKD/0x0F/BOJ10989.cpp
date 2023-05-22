#include<bits/stdc++.h>
using namespace std;

int countnum[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp = 0;
        cin >> tmp;
        countnum[tmp]++;
    }

    for(int i = 1; i < 10001; i++){
        for(int j = 1; j <= countnum[i]; j++){
            cout << i << '\n';
        }
    }
}