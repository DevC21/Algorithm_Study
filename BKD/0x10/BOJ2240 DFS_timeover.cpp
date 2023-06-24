#include<bits/stdc++.h>
using namespace std;

int t, w;
int ans = 0;
int arr[1001];

void func(int time, int move, int pos, int plum){
    if(move > w || time > t){
        ans = max(plum, ans);
        return;
    }

    if(arr[time] == pos)
        plum++;
    ans = max(plum, ans);
    if(pos == 1){
        func(time + 1, move + 1, 2, plum);
        func(time + 1, move, 1, plum);
    }
    else if(pos == 2){
        func(time + 1, move + 1, 1, plum);
        func(time + 1, move, 2, plum);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;

    for(int i = 0; i < t; i++)
        cin >> arr[i];

    func(0, 0, 1, 0);
    func(0, 1, 2, 0);

    cout << ans;
}