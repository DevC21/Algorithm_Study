#include<bits/stdc++.h>
using namespace std;

bool solution(string s) {
    bool answer = true;

    int size = s.size();
    for(auto x : s){
        if(!isdigit(x))
            answer = false;
    }

    if((size == 4 || size == 6) && answer == true){
        return true;
    }
    else 
        return false;
}