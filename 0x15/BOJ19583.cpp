#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, e, q;
    unordered_set<string> enter;
    unordered_set<string> complete;

    cin >> s >> e >> q;

    string a, b;
    while(cin >> a >> b){
        if(a == "" && b == "")
            break;
        if(a <= s){
            enter.insert(b);
            continue;
        }
        if(e <= a && a <= q){
            if(enter.find(b) != enter.end()){
                complete.insert(b);
                continue;
            }
        }
    }

    cout << complete.size() << '\n';
}