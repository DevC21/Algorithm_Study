#include<bits/stdc++.h>
using namespace std;

// ������ ���������� �����ϰ� �־��� ���ڸ� 2������ ǥ������ ��, 1�� ���ڸ� ���� ����

int solution(int n){
    int ans = 0;
    
    while(n != 0){
        ans += n%2;
        n /=2;
    }

    return ans;
}