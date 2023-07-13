#include<bits/stdc++.h>
using namespace std;
#define mod 1000000

int D[5005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    // �ε����� 1���� �����ϱ� ���ؼ� '0'�� �տ� �ٿ���
    s = '0' + s;

    if(s[1] == '0'){
        cout << 0;
        return 0;
    }

    D[0] = 1;
    D[1] = 1;

    for(int i = 2; i <= s.size() - 1; i++){
        //s[i]�� 0�� �ƴ� ��
        if(s[i] > '0')
            D[i] = D[i - 1] % mod; 
        
        // ���� ���ڿ� �ٷ� �� ���ڸ� ���ļ� ������ ��
        // ��, s[i-1](���� �ڸ�) + s[i](���� �ڸ�)�� 10 ~ 26�� ���
        int n  = (s[i - 1] - '0') * 10 + s[i] - '0'; 
        if(10 <= n && 26 >= n)
            D[i] = (D[i] + D[i - 2]) % mod;
    }

    cout << D[s.size() - 1] % mod;
}