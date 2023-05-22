#include<bits/stdc++.h>
using namespace std;

int color[2];
int paper[129][129];

bool same(int r, int c, int n){
    for(int i = r; i < r+n; i++){
        for(int j = c; j < c+n; j++){
            if(paper[r][c] != paper[i][j])
                return false;
        }
    }
    return true;
}

void func(int r, int c, int n){

    if(same(r, c, n)){
        color[paper[r][c]]++;
    }
    else{
        int size = n / 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                func(r + size * i, c + size * j, size);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> paper[i][j];
        }
    }

    func(0, 0, n);

    for(int i = 0; i < 2; i++){
        cout << color[i] << '\n';
    }

}