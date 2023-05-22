#include<bits/stdc++.h>
using namespace std;

int arr[100005];
char carr[1000000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;

    int n, x;
    int idx = 0;
    int cidx = 0;
    int pos = 1;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }



    while(true){
        if(S.empty()){
            S.push(pos);
            pos++;
            carr[cidx] = '+';
            cidx++;
        }

        if(S.top() < arr[idx]){
            S.push(pos);
            pos++;
            carr[cidx] = '+';
            cidx++;
        }
        else if(S.top() == arr[idx]){
            S.pop();
            carr[cidx] = '-';
            cidx++;
            idx++;
        }
        else {
            cout << "NO" << '\n';
            break;
        }

        if( idx == n){
            for(int i = 0; i < cidx; i++)
                cout << carr[i] << '\n';
            break;
        }
    }
}