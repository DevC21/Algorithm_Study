#include<bits/stdc++.h>
using namespace std;

int t;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    cin.ignore();

    while(t--){
        getline(cin, s);
        istringstream ss(s);
        string buffer = "";
        while(getline(ss, buffer, ' ')){
            reverse(buffer.begin(), buffer.end());
            cout << buffer << ' ';
        }
        cout << '\n';
    }

}