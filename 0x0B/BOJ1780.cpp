#include<bits/stdc++.h>
using namespace std;

int num[3];
int paper[2200][2200];

bool checksame(int r, int c, int n){
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
            if(paper[r][c] != paper[i][j])
                return false;
        }
    }
    return true;
}

void func(int r, int c, int n){
    if(checksame(r, c, n)){
        num[paper[r][c]+1]++;
    }
    else {
        int size = n / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
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

    for(int i = 0; i < 3; i++){
        cout << num[i] << '\n';
    }
}