#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// BOJ1495 기타리스트와 비슷한 문제

int n;
int arr[105];
// i + 1번째 차례에 +, - 연산으로 숫자 j를 만들 수 있는 경우의 수
ll D[105][21];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 첫번째로 arr[0]이 오는 경우의 수는 하나뿐이다.
    D[0][arr[0]] = 1;

    //n - 2번째까지의 등식합만 필요 하므로 i < n - 1
    for(int i = 1; i < n - 1; i++){
        for(int j = 0; j <= 20; j++){
            // D[i - 1][j]가 0이면 이전까지 주어진 숫자로는 j를 만들 수 없다는 뜻
            if(D[i - 1][j] == 0)
                continue;

            // +, - 연산
            int plus = j + arr[i];
            int minus = j - arr[i];

            // +, - 연산의 결과가 0 이상 20 이하라면
            // i - 1번째로 j를 만들 수 있는 경우의 수는
            // i번째로 +, - 연산의 결과로 만들 수 있는 경우의 수이다.
            if(plus <= 20)
                D[i][plus] += D[i - 1][j];
            if(minus >= 0)
                D[i][minus] += D[i - 1][j];
        }
    }

    // n - 2번째까지의 등식합이 n - 1번째 숫자가 되야한다.
    cout << D[n - 2][arr[n - 1]];
}