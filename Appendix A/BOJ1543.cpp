#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string docu;
    getline(cin, docu);

    string word;
    getline(cin, word);

    int cnt = 0;
    int st = docu.find(word);
    while(st != -1){
        cnt++;
        st = docu.find(word, st + word.size());
    }

    cout << cnt;
}