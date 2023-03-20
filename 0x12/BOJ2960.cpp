#include<bits/stdc++.h>
using namespace std;

vector<bool> state(1001, true);
int num = 1;
int cnt = 0;
int n, k;

void sieve(int n){
    state[1] = false;
    for(int i = 2; i <= n; i++){
        if(!state[i])
            continue;
        for(int j = i; j <= n; j += i){
            if(!state[j])
                continue;
            state[j] = false;
            num = j;
            cnt++;
            if(cnt == k)
                return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    sieve(n);

    cout << num;
}