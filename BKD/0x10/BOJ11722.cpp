#include<bits/stdc++.h>
using namespace std;

int n, ans;
int arr[1005];
// D[i]는 i번 인덱스까지의 가장 긴 감소하는 부분수열의 최대 길이이다.
int D[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++){
        D[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j] && D[j] + 1 > D[i])
                D[i] = D[j] + 1;
        }
    }

    for(int i = 0; i < n; i++)
        if(D[i] > ans)
            ans = D[i];

    cout << ans;
}