#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 문제 해설 : https://maloveforme.tistory.com/38

vector<int> solution(int n, ll left, ll right) {
    vector<int> answer;

    // 배열의 값은 규칙에 따라 생성되는 (x, y)에서 x와 y 중 큰 값이 된다
    // x의 값은 i / n
    // y의 값은 i % n
    // 배열을 (1,1)부터 시작하기때문에 + 1
    for(ll i = left; i <= right; i++)
        answer.push_back(max(i / n, i % n) + 1);

    return answer;
}