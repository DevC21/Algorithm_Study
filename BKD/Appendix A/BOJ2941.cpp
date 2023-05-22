#include<bits/stdc++.h>
using namespace std;

void ReplaceAll(string& str, string from, string to){
    int st = str.find(from);
    while(st != -1){
        str.replace(st, from.size(), to);
        st = str.find(from);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    getline(cin, word);

    vector<string> alpha = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for(auto x : alpha){
        ReplaceAll(word, x, "#");
    }

    cout << word.size();
}