#include <bits/stdc++.h>
using namespace std;

// ���� �����ϰ� �ִ��� Ȯ��
// (x, y)�� ���� ������ isused1[y]�� true
bool isused1[40];
// / ���� �밢���� �����ϰ� �ִ��� Ȯ��
// (x, y)�� ���� ������ isused2[x+y]�� true
bool isused2[40]; 
// \ ���� �밢���� �����ϰ� �ִ��� Ȯ��
// (x, y)�� ���� ������ isused3[x-y+n-1]�� true
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
        // ���°���Ʈ���� �� ���� �����ϸ� (�Լ��� ���ٰ� ���� ��)
        // �ڷ� ���ƿͼ� i�� �����ϰ� �ִ� ������ Ǯ��
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