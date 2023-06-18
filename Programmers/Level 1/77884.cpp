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

int solution(int left, int right) {
    int answer = 0;

    for(int i = left; i <= right; i++){
        if(sumdivisors(i) % 2 == 0)
            answer += i;
        else
            answer -= i;
    }

    return answer;
}