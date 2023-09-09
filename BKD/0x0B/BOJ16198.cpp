#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> marbles;
int max_val;

void recur(int sum){
    if(marbles.size() == 3){
        sum += marbles[0] * marbles[2];
        max_val = max(max_val, sum);
        return;
    }

    for(int i = 1; i < marbles.size() - 1; i++){
        int tmp = marbles[i];
        int tmp_sum = sum + marbles[i - 1] * marbles[i + 1];
        
        marbles.erase(marbles.begin() + i);
        recur(tmp_sum);
        marbles.emplace(marbles.begin() + i, tmp);
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

    recur(0);

    cout << max_val;
}