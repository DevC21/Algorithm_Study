#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string pattern;
    cin >> n >> pattern;
    int star = pattern.find('*');
    string front = pattern.substr(0, star);
    string rear = pattern.substr(star + 1, pattern.size() - star);

    while(n--){
        bool check = true;
        string file;
        cin >> file;

        if(front.size() + rear.size() > file.size()){
            cout << "NE" << '\n';
            continue;
        }

        for(int i = 0; i < star; i++){
            if(front[i] != file[i]){
                check = false;
                break;
            }
        }

        if((file.find(rear, file.size() - rear.size()) == -1))
            check = false;

        if(check) cout << "DA" << '\n';
        else cout << "NE" << '\n';
    }
}