#include<bits/stdc++.h>
using namespace std;



int main(){
    list<int> L = {};

    int n, k, num;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        L.push_back(i+1);
    }

    auto t = L.begin();

    cout << '<';
    for(int i = 0; i < n; i++){
        int j = 0;
        while(j < k){
            if( t == L.end())
                t = L.begin();
            t++;
            j++;
        }
        if( t != L.begin()){
            t--;
            num = *t;
            t = L.erase(t);
        }

        cout << num;
        if( i != n-1){
            cout << ',' << ' ';
        }
    }
    cout << '>';
}