#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        string ans;
        cin.ignore();
        getline(cin, ans);

        while(true){
            string str;
            cin >> str;
            if(str != "what"){
                cin >> str;
                cin >> str;

                int pos = 0;
                while(ans.find(str, pos) != -1){
                    pos = ans.find(str, pos);
                    if(pos != 0)
                        if(ans[pos - 1] != ' '){
                            pos = ans.find(str, pos + str.size());
                            continue;
                        }

                    ans.erase(pos, str.size() + 1);
                }
            }
            else{
                for(int i = 0; i < 4; i++){
                    cin >> str;
                }
                cout << ans << '\n';
                break;
            }
        }
    }
}