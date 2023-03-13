#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int buffint;
    int total = 0;
    bool minus = false;

    string s;
    stringstream ss;
    cin >> s;

    ss.str(s);

    while (ss >> buffint){
        if(buffint < 0 && minus == true){
            total += buffint;
            continue;
        }
        if(buffint < 0){
            minus = true;
            total += buffint;
            continue;
        }

        if(minus == false){
            total += buffint;
        }
        else {
            total -= buffint;
        }
    }

    cout << total;
}