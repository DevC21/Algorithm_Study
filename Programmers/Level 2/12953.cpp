#include<bits/stdc++.h>
using namespace std;

// 유클리드 호제법을 이용한 최소공배수 구하기
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

/*
n개의 최소공배수
A와 B의 최소공배수 = x
x와 C의 최소공배수 = y
y와 D의 최소공배수 = z
A, B, C, D의 최소공배수는 'z'가 된다
*/

int solution(vector<int> arr) {
    int answer = 0;

    answer = lcm(arr[0], arr[1]);

    for(int i = 2; i < arr.size(); i++)
        answer = lcm(answer, arr[i]);

    return answer;
}