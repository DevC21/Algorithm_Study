#include<bits/stdc++.h>
using namespace std;
#define MAX 10001

int n, k;
int D[10005];
int coin[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> coin[i];

    D[0] = 0;
    for(int i = 1; i <= MAX; i++)
        D[i] = MAX; //D[0]을 제외한 최초 값은 10001(불가능한 경우)

    for (int i = 1; i <= n; i++)
        for (int j = coin[i]; j <= k; j++)            
            //D[j] : j원을 만들 수 있는 동전의 최소 개수
            //D[j - coin[i] : j원을 만들때 coin[i]원을 더 할 경우
            D[j] = min(D[j], D[j - coin[i]] + 1);

    if(D[k] == MAX)
        cout << -1;
    else
        cout << D[k] << '\n';
}