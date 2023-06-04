#include <bits/stdc++.h>
using namespace std;

// 열을 차지하고 있는지 확인
// (x, y)에 퀸이 있으면 isused1[y]를 true
bool isused1[40];
// / 방향 대각선을 차지하고 있는지 확인
// (x, y)에 퀸이 있으면 isused2[x+y]를 true
bool isused2[40]; 
// \ 방향 대각선을 차지하고 있는지 확인
// (x, y)에 퀸이 있으면 isused3[x-y+n-1]을 true
bool isused3[40]; 

int n;
int cnt = 0;

void func(int cur){
    if(cur == n){
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++){
        if(isused1[i] || isused2[cur+i] || isused3[cur-i+n-1])
            continue;
        isused1[i] = 1;
        isused2[i+cur] = 1;
        isused3[cur-i+n-1] = 1;
        func(cur+1);
        // 상태공간트리의 한 끝에 도달하면 (함수를 들어갔다가 나올 때)
        // 뒤로 돌아와서 i가 점유하고 있던 공간이 풀림
        isused1[i] = 0;
        isused2[i+cur] = 0;
        isused3[cur-i+n-1] = 0;
    }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;
}