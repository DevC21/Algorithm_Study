#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int div5;
int div25;
int div125;

// 5의 배수의 개수를 세면, 그것이 자동적으로 10의 배수의 개수가 된다
// 5의 제곱인 25의 배수는 5가 두개이므로, 10의 배수가 한번에 두개씩 나타나는 것
// 세제곱인 125의 배수는 5가 세개이므로, 10의 배수가 한번에 세번씩 나타나는 것
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    div5 = n / 5;
    div25 = n / 25;
    div125 = n / 125;

    cout << div5 + div25 + div125;
}