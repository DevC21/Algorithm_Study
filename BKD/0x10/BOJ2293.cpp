#include<bits/stdc++.h>
using namespace std;

int n, k;
int D[10005];
int coin[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> coin[i];

    D[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = coin[i]; j <= k; j++)
        //i원 동전을 사용하여 j 원을 만들때는 j - coin[i] 금액의 누적 합만 알면 된다.
            D[j] += D[j - coin[i]];

    cout << D[k] << '\n';
}