#include<bits/stdc++.h>
using namespace std;

// 문제 해설 참고 : https://sskl660.tistory.com/90

string a, b;
int D[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    a = "0" + a;
    b = "0" + b;

    for(int i = 1; i < b.size(); i++){
        for(int j = 1; j < a.size(); j++){
            // 두 문자가 같은 경우
            if(b[i] == a[j])
                // 대각선의 값을 참고하여 LCS의 값을 + 1 한다.
                D[i][j] = D[i - 1][j - 1] + 1;
            // 두 문자가 다른 경우
            else
                // 각 문자열의 이전 문자 중 최대 LCS값을 선택.
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
        }
    }
    // 최종으로 탐색한 위치에 LCS의 최대 값이 저장되어 있을 것이다.
    cout << D[b.size() - 1][a.size() - 1];
}