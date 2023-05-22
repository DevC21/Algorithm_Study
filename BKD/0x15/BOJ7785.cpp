#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<string> s;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        string name, co;
        cin >> name >> co;

        if(co == "enter"){
            s.insert(name);
        }
        else if(co == "leave"){
            s.erase(name);
        }
    }

    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());

    for(auto x : ans){
        cout << x << '\n';
    }
}