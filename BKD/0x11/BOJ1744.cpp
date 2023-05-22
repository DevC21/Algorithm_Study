#include<bits/stdc++.h>
using namespace std;

int pos[51];
int neg[51];
int poscnt, negcnt;
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num > 0){
            pos[poscnt] = num;
            poscnt++;
        }
        else{
            neg[negcnt] = num;
            negcnt++;
        }
    }

    sort(pos, pos+poscnt, greater<>());
    sort(neg, neg+negcnt);

    for(int i = 0; i < poscnt; i++){
        if(pos[i] == 1 || pos[i+1] == 1){
            ans += pos[i] + pos[i+1];
            i++;
        }
        else if(i == poscnt - 1){
            ans += pos[i];
        }
        else{
            ans += pos[i] * pos[i+1];
            i++;
        }
    }

    for(int i = 0; i < negcnt; i++){
        if(i == negcnt - 1){
            ans += neg[i];
        }
        else{
            ans += neg[i] * neg[i+1];
            i++;
        }
    }

    cout << ans;
}