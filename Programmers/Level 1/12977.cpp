#include<bits/stdc++.h>
using namespace std;

// 에라토스테네스의 체 + 백트래킹

int answer;

vector<bool> state(3000+5, true);

int n, m;
vector<int> vec;
int arr[8];
bool isused[1005];

void func(int cur){
    if(cur == m){
        int sum = 0;
        for(int i = 0; i < m; i++)
            sum += arr[i];
        if(state[sum])
            answer++;
        return;
    }

    for(int i = 0; i < n; i++){
        if(!isused[vec[i]]){
            if(cur != 0){
                if(arr[cur - 1] > vec[i])
                    continue;
            }
            arr[cur] = vec[i];
            isused[vec[i]] = 1;
            func(cur + 1);
            isused[vec[i]] = 0;
        }
    }
}

void sieve(int n){
    state[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(state[i] == false)
            continue;
        for(int j = i * i; j <= n; j += i)
            state[j] = false;
    }
}

int solution(vector<int> nums) {

    sieve(3005);

    vec = nums;
    sort(vec.begin(), vec.end());
    n = nums.size();
    m = 3;

    func(0);

    return answer;
}