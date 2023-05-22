#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);



    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        multiset<int> ms;

        int k;

        cin >> k;

        for(int j = 0; j < k; j++){
            int n;
            char c;

            cin >> c >> n;

            switch(c){
                case('I'):{
                    ms.insert(n);
                    break;
                }
                case('D'):{
                    if(ms.empty())
                        break;
                    if(n == 1){
                        ms.erase(prev(ms.end()));
                    }
                    else if(n == -1){
                        ms.erase(ms.begin());
                    }
                    break;
                }
            }
        }

        if(ms.empty())
            cout << "EMPTY\n";
        else{
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
}