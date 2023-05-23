#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int a[1'000'005];
int ans[1'000'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    // �⺻���� ���̵��� 6198�� ���� ���� �ٹ̱�� �����ϳ�
    // 0�� �迭���� �����ϴ°� �ƴ϶� ������ �迭���� �����ؾ���
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty()){
            if(s.top() > a[i])
                break;
            s.pop();
        }
        
        // ������ �迭���� ���� ������ 
        // 0�� �迭���� ��ū���� ����ؾ� �ϱ⶧����
        // ����� ans �迭�� �����Ѵ�.
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();

        s.push(a[i]);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
}