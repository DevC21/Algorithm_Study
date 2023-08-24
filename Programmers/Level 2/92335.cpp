#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 1. n�� string������ k������ �ٲٴ� ��� �����
string k_radix(int n, int k){
    string s = "";

    while(n != 0){
        s += to_string(n % k);
        n /= k;
    }

    reverse(s.begin(), s.end());

    return s;
}

// 2. string�� ��0���� �������� split�ϴ� ��� �����
vector<string> split(string s, string sep){
    vector<string> ret;
    int pos = 0;
    while(pos < s.size()){
        int nxt_pos = s.find(sep, pos);
        if(nxt_pos == -1) nxt_pos = s.size();
        if(nxt_pos - pos > 0)
            ret.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + sep.size();
    }
    return ret;
}

// 3. ���� n�� �Ҽ����� �˻��ϴ� ��� �����
bool isprime(ll n){
    if(n == 1) return 0;
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int solution(int n, int k) {
    int answer = 0;

    string s = k_radix(n, k);

    vector<string> split_s = split(s, "0");

    // 4. 3�� ���ǿ� �����ϴ� answer�� ����ϱ�
    for(auto x : split_s)
        if(isprime(stol(x)))
            answer++;
    
    return answer;
}