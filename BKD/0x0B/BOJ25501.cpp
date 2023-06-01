#include<bits/stdc++.h>
using namespace std;

int cnt;

int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cnt = 0;
        string s;
        cin >> s;

        cout << isPalindrome(s.c_str()) << ' ' << cnt << '\n';
    }
}