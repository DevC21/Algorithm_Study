#include<bits/stdc++.h>
using namespace std;

string arr[1001];

bool cmp(const string &a, const string &b){
    return a < b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    for(int i = 0; i < s.length(); i++){
        arr[i] = s.substr(i, s.length());
    }

    sort(arr, arr+s.length(), cmp);

    for(int i = 0; i < s.length(); i++){
        cout << arr[i] << '\n';
    }
}