#include<bits/stdc++.h>
using namespace std;

map<string, int> m;
vector<int> nCr;

// nCr = n-1Cr-1 + n-1Cr 공식을 사용하여 재귀적으로 구현
int combination(int n, int r){
    // n개중에 n개를 고르거나 0개를 고르는 경우의 수는 1개
    if(n == r || r == 0) 
        return 1; 
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    for(auto x : clothes)
        m[x[1]]++;
    
    // 각 의상 종류별로 1개를 입거나 안입을 수 있다.
    // nC1 + nC0만 구해서 더해줌
    for(auto x : m){
        int sum = 0;
        for(int i = 0; i <= 1; i++)
            sum += combination(x.second, i);
        nCr.push_back(sum);
    }

    // 조건부 확률 : 두 확률이 동시에 일어날 확률은 두 확률의 곱과 같다.
    for(auto x : nCr)
        answer *= x;
    // 의상을 최소 1개는 입는다 
    // 모든 의상 종류를 하나도 안입는 가짓수 1을 최종값에서 뺀다.
    answer--;

    // 일반화
    // hash_table = {종류1: n, 종류2: m, 종류3: k, 종류4: p} 이렇게 주어졌다면
    // (nC1 + nC0) x (mC1 + mC0) x (kC1 + kC0) x (pC1 + pC0) - 1

    return answer;
}