#include<bits/stdc++.h>
using namespace std;

void func(int a){
    if(a == 0) return;
        func(a-1);
}

int main() {
    func(1000000);
    cout << "done";
}