#include<bits/stdc++.h>
using namespace std;

int arrA[20005];
int arrB[20005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        int n, m;
        int cnt = 0;
        cin >> n >> m;
        for(int j = 0; j < n; j++){
            cin >> arrA[j];
        }
        for(int j = 0; j < m; j++){
            cin >> arrB[j];
        }
        
        sort(arrA, arrA+n);
        sort(arrB, arrB+m);

        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(arrA[j] < arrB[k])
                    break;
                if(arrA[j] > arrB[k])
                    cnt++;
            }
        }
        cout << cnt << '\n';
    }
}