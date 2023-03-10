#include<bits/stdc++.h>
using namespace std;

int level[105];
int cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> level[i];
    }    

    for(int i = n-1; i >= 0; i--){
        // while(level[i] <= level[i-1]){
        //     level[i-1]--;
        //     cnt++;
        // }
        if(level[i] <= level[i-1]){
            cnt += level[i-1] - level[i] + 1;
            level[i-1] = level[i-1] - (level[i-1] - level[i] + 1);
        }
    }

    cout << cnt;
}