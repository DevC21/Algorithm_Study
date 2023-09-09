#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> marbles;
int max_val;

void recur(int w, vector<int> marbles, int sum){
    if(marbles.size() == 2){
        max_val = max(max_val, sum);
        return;
    }

    for(int i = 1; i < marbles.size() - 1; i++){
        vector<int> tmp = marbles;
        int tmp_sum = sum + tmp[i - 1] * tmp[i + 1];
        tmp.erase(tmp.begin() + i);
        recur(i, tmp, tmp_sum);
    }
}

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        marbles.push_back(num);
    }

    for(int i = 1; i < n - 1; i++)
        recur(i, marbles, 0);

    cout << max_val;
}