#include<bits/stdc++.h>
using namespace std;

string serial[51];

bool cmp(const string &a, const string &b){

    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    
    int sumA = 0;
    int sumB = 0;
    for(char c : a){
        if(isdigit(c))
            sumA += c - 48;
    }
    for(char c : b){
        if(isdigit(c))
            sumB += c - 48;
    }
    if(sumA != sumB){
        return sumA < sumB;
    }

    return a < b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> serial[i];
    }

    sort(serial, serial+n, cmp);

    for(int i = 0 ; i < n; i++){
        cout << serial[i] << '\n';
    }
}