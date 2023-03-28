#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, string> g;
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string group;
        int num;
        cin >> group >> num;

        for(int j = 0; j < num; j++){
            string member;
            cin >> member;
            g[member] = group;
        }
    }

    for(int i = 0; i < m; i++){
        string target;
        int type;
        
        cin >> target >> type;

        switch(type){
            case 0:{
                vector<string> keys;
                for (auto it = g.begin(); it != g.end(); it++) {
                    if (it->second == target) {
                        keys.push_back(it->first);
                    }
                }

                sort(keys.begin(), keys.end());

                for (const auto &key: keys) {
                    cout << key << '\n';
                }
                break;
            }
            case 1:{
                cout << g[target] << '\n';
                break;
            }
        }
    }
}