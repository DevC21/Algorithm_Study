#include<bits/stdc++.h>
using namespace std;

// 11726번 2xn 타일링과 같은 피보나치 수 문제
/*
N-2의 경우의 수들엔 "맨 뒤에" 00을 붙이고, 
N-1의 경우의 수들엔 "맨 앞에" 1을 붙여보면
N = 5일때
N-2의 맨 뒤에 00추가 -> 00100,10000,11100
N-1의 맨 앞에 1 추가-> 10011,10000,11001,1100,11111
*/

int n;
int D[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[1] = 1;
    D[2] = 2;

    if(n == 1){
        cout << 1;
        return 0;
    }
    else if(n == 2){
        cout << 2;
        return 0;
    }

    for(int i = 3; i <=n; i++){
        D[i] = (D[i-2] + D[i-1])% 15746;
    }

    cout << D[n] % 15746;
}