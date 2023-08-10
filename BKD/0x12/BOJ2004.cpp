#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// ���� 0�� ����
// ���� nCm = n! / (n-m)! * m!
// n!, (n-m)!, m!�� 2�� 5�� ������ ������ ���Ѵ�.
// n!�� �������� (n-m)!�� m!�� ������ ����.

ll n, m;
ll n_two;
ll nm_two;
ll m_two;
ll n_five;
ll nm_five;
ll m_five;

ll two_count(ll num){
    ll sqr2 = 2;
    ll cnt = 0;
    while(sqr2 <= n){
        cnt += num / sqr2;
        sqr2 *= 2;
    }

    return cnt;
}

ll five_count(ll num){
    ll sqr5 = 5;
    ll cnt = 0;
    while(sqr5 <= n){
        cnt += num / sqr5;
        sqr5 *= 5;
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    n_two = two_count(n);
    nm_two = two_count(n - m);
    m_two = two_count(m);

    n_five = five_count(n);
    nm_five = five_count(n - m);
    m_five = five_count(m);

    cout << min(n_two - (nm_two + m_two), n_five - (nm_five + m_five));
}