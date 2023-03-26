#include<bits/stdc++.h>
using namespace std;

string NumToName[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, int> NameToNum;
    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string name;
        cin >> name;
        NumToName[i] = name;
        NameToNum[name] = i;
    }

    for(int i = 0; i < m; i++){
        string Q;
        cin >> Q;
        if(atoi(Q.c_str()) != 0)
            cout << NumToName[atoi(Q.c_str())] << '\n';
        else
            cout << NameToNum[Q] << '\n';
    }
}