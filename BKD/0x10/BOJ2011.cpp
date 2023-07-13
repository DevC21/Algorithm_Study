#include<bits/stdc++.h>
using namespace std;
#define mod 1000000

int D[5005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    // 인덱스를 1부터 생각하기 위해서 '0'를 앞에 붙여줌
    s = '0' + s;

    if(s[1] == '0'){
        cout << 0;
        return 0;
    }

    D[0] = 1;
    D[1] = 1;

    for(int i = 2; i <= s.size() - 1; i++){
        //s[i]이 0이 아닐 때
        if(s[i] > '0')
            D[i] = D[i - 1] % mod; 
        
        // 현재 숫자와 바로 앞 숫자를 합쳐서 생각할 때
        // 즉, s[i-1](십의 자리) + s[i](일의 자리)가 10 ~ 26일 경우
        int n  = (s[i - 1] - '0') * 10 + s[i] - '0'; 
        if(10 <= n && 26 >= n)
            D[i] = (D[i] + D[i - 2]) % mod;
    }

    cout << D[s.size() - 1] % mod;
}