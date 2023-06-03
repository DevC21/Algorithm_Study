#include<bits/stdc++.h>
using namespace std;

// 최대 값 k = 10 r = 3*2^10 = 3072, c = 3072 * 2 - 1 = 6143
char arr[3072][6143];

// 최소 단위인 n == 3 일때
void drawstar(int r, int c){
    //  *   
    arr[r][c] = '*';

    // * *  
    arr[r + 1][c - 1] = '*';
    arr[r + 1][c + 1] = '*';

    //***** 
    for(int i = 0 ; i < 5; i++){
        arr[r + 2][c - 2 + i] = '*';
    }
}

void triangle(int n, int r, int c){
    if(n == 3){
        drawstar(r, c);
        return;
    }

    // 위쪽 삼각형의 높이와 꼭대기 좌표
    triangle(n / 2, r, c); 
    // 왼쪽 아래 삼각형의 높이와 꼭대기 좌표
    triangle(n / 2, r + n / 2, c - n / 2); 
    // 오른쪽 아래 삼각형의 높이와 꼭대기 좌표
    triangle(n / 2, r + n / 2, c + n / 2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2 * n - 1; j++)
            arr[i][j] = ' ';


    triangle(n, 0, n - 1);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2 * n - 1; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
}