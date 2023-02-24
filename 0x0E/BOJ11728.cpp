#include<bits/stdc++.h>
using namespace std;

int arrA[1000005];
int arrB[1000005];
int mergearr[2000005];
int n, m, idx;

void merge(int A, int B){
    if(A >= n && B >= m){
        return;
    }

    if(A >= n){
        mergearr[idx] = arrB[B];
        idx++;
        merge(A, B+1);
    }
    else if(B >= m){
        mergearr[idx] = arrA[A];
        idx++;
        merge(A+1, B);
    }
    else if(arrA[A] > arrB[B]){
        mergearr[idx] = arrB[B];
        idx++;
        merge(A, B+1);
    }
    else if(arrA[A] < arrB[B]){
        mergearr[idx] = arrA[A];
        idx++;
        merge(A+1, B);
    }
    else if(arrA[A] == arrB[B]){
        mergearr[idx] = arrA[A];
        idx++;
        mergearr[idx] = arrB[B];
        idx++;
        merge(A+1, B+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> arrA[i];
    }

    for(int i = 0; i < m; i++){
        cin >> arrB[i];
    }

    merge(0, 0);

    for(int i = 0; i < n+m; i++){
        cout << mergearr[i] << ' ';
    }
}