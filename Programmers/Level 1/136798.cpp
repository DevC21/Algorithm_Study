#include<bits/stdc++.h>
using namespace std;

int sumdivisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        // i * i = n�� ��쿡�� �ߺ����� ���°��� �����ϱ� ���� ������ ���� �ִ´�.
        if (i * i == n) sum++;
        else if (n % i == 0) sum += 2;
    }
    return sum;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    int divisors = 0;
    for(int i = 1; i <= number; i++){
        divisors = sumdivisors(i);
        if(divisors <= limit) answer += divisors;
        else if(divisors > limit) answer += power;
    }

    return answer;
}