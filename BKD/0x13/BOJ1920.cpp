#include<bits/stdc++.h>
using namespace std;

int A[100005];
int n;

int binarysearch(int target){
    int st = 0;
    int en = n-1;
    int mid = (st+en)/2;
    while(st <= en){
        if(A[mid] < target){
            st = mid+1;
        }
        else if(A[mid] > target){
            en = mid-1;
        }
        mid = (st+en)/2;
        if(A[mid] == target)
            return 1;
    }

    return 0;
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
        cout << binarysearch(t) << '\n';
    }
}