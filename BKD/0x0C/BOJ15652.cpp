#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];

void func(int cur){
    if(cur == m){
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        // �񳻸����� ����
        // arr[cur]�� ���õǴ� i �� arr[cur - 1]���� ������ �ȵȴ�.
        if(cur != 0)
            if(arr[cur - 1] > i)
                continue;
        arr[cur] = i;
        func(cur + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
}