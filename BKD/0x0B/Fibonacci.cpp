#include<bits/stdc++.h>
using namespace std;

long fibonacci(long n) {
    if (n <= 2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fibonacci(3);
}