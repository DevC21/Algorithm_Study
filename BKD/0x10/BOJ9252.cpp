#include<bits/stdc++.h>
using namespace std;

// 문제 해설 참고 : https://www.crocus.co.kr/787

string a, b, LCS;
int D[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    a = "0" + a;
    b = "0" + b;

    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            // 두 문자가 같은 경우
            if(a[i] == b[j])
                // 대각선의 값을 참고하여 LCS의 값을 + 1 한다.
                D[i][j] = D[i - 1][j - 1] + 1;
            // 두 문자가 다른 경우
            else
                // 각 문자열의 이전 문자 중 최대 LCS값을 선택.
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
        }
    }

    int i = a.size() - 1;
    int j = b.size() - 1;
    while (D[i][j] != 0){
        /*
            역 경로추적 - 테이블을 구할 때 했던 작업을 반대로 진행한다.
            D[a.size() - 1][b.size() - 1]부터 시작하여 자신과 같은 숫자가 있는곳까지 따라간다.
            그리고 왼쪽, 위쪽 둘중 둘다 같은 수가 없다면, 대각선 방향 값이 현재 값 - 1인지 확인해보고 그 수를 따라간다.
            이것을 테이블에서 0이 나타날 때 까지 계속해서 반복한다.
        */
        if (D[i][j] == D[i][j - 1])
            j--;
        else if (D[i][j] == D[i - 1][j])
            i--;
        else if (D[i][j] - 1 == D[i - 1][j - 1]){
            LCS.insert(LCS.begin(), a[i]);
            i--;
            j--;
        }
    }

    // 최종으로 탐색한 위치에 LCS의 최대 값이 저장되어 있을 것이다.
    cout << D[a.size() - 1][b.size() - 1] << '\n';
    if(LCS.size() != 0)
        cout << LCS;
}