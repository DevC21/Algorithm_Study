#include<bits/stdc++.h>
using namespace std;

int n = -1;
vector<int> vec;
int arr[14];
bool isused[14];

void lotto(int cur){
    if(cur == 6){
        for(int i =0; i < 6; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(!isused[i]){
            if(cur > 0 && arr[cur - 1] > vec[i])
                continue;
            isused[i] = 1;
            arr[cur] = vec[i];
            lotto(cur + 1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(n != 0){
        cin >> n;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            vec.push_back(num);
        }

        lotto(0);
        cout << '\n';
        vec.clear();
    }
}