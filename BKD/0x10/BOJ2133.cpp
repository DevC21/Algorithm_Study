#include<bits/stdc++.h>
using namespace std;

int n;
int D[31];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    D[0] = 1;
    // n이 홀수 일 경우 2×1, 1×2 크기의 타일로 마지막 한칸을 채우는게 불가능하다.
    D[1] = 0;
    D[2] = 3;

    for(int i = 4; i <= n; i += 2){
        // 3 x n 크기의 벽을 3 x (n - 2) + 3 x 2로 채우는 경우
        D[i] = D[i - 2] * D[2];
        // 위 케이스와 중복되지 않기 위해서 3 x 4부터 발생하는 특수한 모양들(2개)을
        // 마지막 타일에 사용한 경우들을 더해준다.
        for(int j = i - 4; j >= 0; j -= 2)
            D[i] += D[j] * 2;
    }

    cout << D[n];
}