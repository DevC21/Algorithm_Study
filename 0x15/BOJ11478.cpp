#include<bits/stdc++.h>
using namespace std;

unordered_set<string> s;
string str, tmp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.length(); ++i) {
        tmp = "";
        for (int j = i; j < str.length(); ++j) {
            tmp += str[j];
            s.insert(tmp);
        }
    }

    cout << s.size();
}