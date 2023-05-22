#include<bits/stdc++.h>
using namespace std;

int A[500005];
int n;

int lower_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(A[mid] >= target){
            en = mid;
        }
        else{
            st = mid+1;
        }
    }
    return st;
}

int upper_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(A[mid] > target){
            en = mid;
        }
        else{
            st = mid+1;
        }
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort(A, A+n);

    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        cout << upper_idx(t, n) - lower_idx(t, n) << ' ';
    }
}