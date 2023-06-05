#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int cur){
    if(cur == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!isused[i]){
            if(cur != 0)
                if(arr[cur - 1] > i)
                    continue;
            isused[i] = 1;
            arr[cur] = i;
            func(cur + 1);
            isused[i] = 0;
            arr[cur] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
}