#include<bits/stdc++.h>
using namespace std;

int zero;
int one;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    char cur;

    for(char c : s){
        if(cur != c){
            cur = c;
            if(cur == '0'){
                zero++;
            }
            else if(cur == '1'){
                one++;
            }
        }
    }

    cout << min(zero, one);
}