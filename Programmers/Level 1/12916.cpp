#include<bits/stdc++.h>
using namespace std;

bool solution(string s){
    int p = 0;
    int y = 0;

    for(auto c : s){
        if(c == 'p' || c == 'P')
            p++;
        else if(c == 'y' || c == 'Y')
            y++;
    }

    if(p == y)
        return true;
    else
        return false;
}