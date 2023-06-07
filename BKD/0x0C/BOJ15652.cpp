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
        // 비내림차순 선택
        // arr[cur]에 선택되는 i 가 arr[cur - 1]보다 작으면 안된다.
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