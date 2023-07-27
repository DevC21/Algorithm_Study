#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> ans;
int arr[20];

void func(int sum, int len){
    if(sum > n)
        return;
    if(sum == n){
        vector<int> tmp;
        for(int i = 0; i < len; i++)
            tmp.push_back(arr[i]);
        ans.push_back(tmp);
        return;
    }

    for(int i = 1; i <= 3; i++){
        arr[len] = i;
        len++;
        func(sum + i, len);
        len--;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    func(0, 0);

    sort(ans.begin(), ans.end());

    k--;
    if(k >= ans.size()){
        cout << -1;
        return 0;
    }
    
    for(int i = 0; i < ans[k].size(); i++){
        if(i == ans[k].size() - 1)
            cout << ans[k][i];
        else
            cout << ans[k][i] << '+';
    }
}