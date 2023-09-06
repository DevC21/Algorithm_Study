#include<bits/stdc++.h>
using namespace std;

int arr[11];
int n;
int op[4];
int min_val = INT32_MAX;
int max_val = -INT32_MAX;

void recur(int depth, int tot,int op[]){
    if(depth == n){
        min_val = min(min_val, tot);
        max_val = max(max_val, tot);
        return;
    }

    for(int i = 0; i < 4; i++){
        if(op[i] > 0){
            op[i]--;
            if(i == 0)
                recur(depth + 1, tot + arr[depth], op);
            else if(i == 1)
                recur(depth + 1, tot - arr[depth], op);
            else if(i == 2)
                recur(depth + 1, tot * arr[depth], op);
            else if(i == 3)
                recur(depth + 1, tot / arr[depth], op);
            op[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < 4; i++)
        cin >> op[i];

    recur(1, arr[0], op);

    cout << max_val << '\n';
    cout << min_val << '\n';
}