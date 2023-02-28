#include<bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    else{
        return a < b;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;

    cin >> n;

    vector<string>s(n);

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    sort(s.begin(), s.end(), cmp);

    s.erase(unique(s.begin(), s.end()), s.end());

    for(string &ss : s){
        cout << ss << '\n';
    }
}