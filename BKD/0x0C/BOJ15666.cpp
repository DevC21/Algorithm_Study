#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;
int arr[8];
int isused[8];

void func(int cur){
    if(cur == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(i >= 1 && vec[i - 1] == vec[i] && !isused[i - 1])
            continue;
        if(cur > 0){
            if(arr[cur - 1] > vec[i])
                continue;
        }
        isused[i] = 1;
        arr[cur] = vec[i];
        func(cur + 1);
        isused[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    func(0);
}