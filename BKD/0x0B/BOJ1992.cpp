#include<bits/stdc++.h>
using namespace std;

int screen[65][65];

bool same(int r, int c, int n){
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
            if(screen[r][c] != screen[i][j])
                return false;
        }
    }
    return true;
}

void func(int r, int c, int n){

    if(same(r,c,n)){
        cout << screen[r][c];
    }
    else{
        cout << '(';
        int size = n / 2;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                func(r + size * i, c + size * j, size);
            }
        }
        cout << ')';
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '0'){
                screen[i][j] = 0;
            }
            else if(s[j] = '1'){
                screen[i][j] = 1;
            }
        }
    }

    func(0, 0, n);
}