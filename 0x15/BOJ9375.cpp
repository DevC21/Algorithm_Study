#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t-- > 0){
        unordered_map<string, int> m;

        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            string name, sort;
            cin >> name >> sort;

            m[sort]++;
        }

        int ans = 1;
        for (auto i : m){
            ans *= (i.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }
}