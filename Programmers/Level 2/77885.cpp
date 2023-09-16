#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 2진법으로 변환할때
// 가장 오른쪽에 처음으로 나오는 0을 1으로 바꾸고
// 그 바로 오른쪽 자리를 0으로 바꾸면 조건에 만족하는 수가 된다.

// 조건에 만족하는 수 f(n)은 주어진 수 n을 2로 나누어보면서 가장 처음 나오는 0의 자릿수 i에 따라
// f(n) = n + 2^(i+1) - n^i가 된다
// 이때, 짝수는 항상 맨 오른쪽 비트가 0이므로 n에서 1을 더한 값이다.

vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;

    ll tmp;
    int cnt;

    for(int i = 0; i < numbers.size(); i++){
        tmp = numbers[i];
        cnt = 0;
        if(numbers[i] % 2 == 0){
            answer.push_back(tmp + 1);
            continue;
        }

        while(tmp > 0){
            if(tmp % 2 == 0)
                break;
            tmp /= 2;
            cnt++;
        }

        tmp = numbers[i] + pow(2, cnt) - pow(2, cnt - 1);
        answer.push_back(tmp);
    }

    return answer;
}

int main(){
    vector<ll> ans = solution({2, 7});

    return 0;
}
