#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 1'000'000'000

int n;
ll D[1'000'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[0] = 0;
    D[1] = 1;

    int absN = abs(n);
    for(int i = 2; i <= absN; i++)
        D[i] = (D[i - 1] + D[i - 2]) % mod;


    if(n < 0){
    // �Ǻ���ġ�� ���� �������� Ȯ���� ���
    // ¦����° �Ǻ���ġ ���� ����, Ȧ����° �Ǻ���ġ ���� ����� ��Ÿ����.
        if(absN % 2 == 0)
            cout << -1 << '\n';
        else
            cout << 1 << '\n';
        cout << D[absN] % mod;
    }
    else{
        if(n == 0)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
        cout << D[absN] % mod;
    }

    return 0;
}